#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
 In open addressing we make hash table of simple array of size m to store the data of size n
load factor is n/m
we make hash function and store the data at hashed index ..if we find collision values then we search for other empty slot by probing
probing can be of many types:
1. linear probing            // make cluster
2. quadratic probing        // make secondary cluster and insert is not guranteed even if space available
3. or Double Hashing can be the solution

requirements : lets say we have data of n size then our hash table size has to greater or equal to n
It is cache friendly // as memory allocation is continous

lets implement !!!


INSERT:: for insert we find NULL space and then insert and ensure if we dont get NULL space we return

DELETE:: for deletion we ensure first whether the key is present or not by iterating over hash table unless we find a NULL value or encounter the same initial index with which we started
          and if we get the key value then rather than making it as NULL we mark it as deleted ...here for marking cell as deleted ,i assigned int_max value to it

SEARCH ::for search we simply iterate untill we find the key , encounter a NULL value or we reach the same initial index we started with */

class openhash
{
public:
    int m;
    int *array;
    int deleted = -1001;

    openhash(int data_size = 7)
    {
        m = data_size;

        array = new int[m];
        int i = 0;

        while (i < m)
        {
            array[i] = NULL;
            i++;
        }
    }

    int hash1(int key) { return key % m; } // hashing function 1

    int hash2(int key) { return key % (m - 1); } // hashing function 2 for double hash

    // lp=linear probing
    // qp = quadratic probing
    // dh=double hashing

    void insertlp(int key)
    {
        int probe = hash1(key);
        int chk = probe;
        int i = 0;

        while (array[(probe + i) % m] != NULL)
        {
            if (((probe + i) % m == chk) && (i != 0))
            {
                break;
            }

            i++;
        }

        if (((probe + i) % m == chk) && (i != 0))
        {
            return;
        }

        array[(probe + i) % m] = key;
    };

    void insertqp(int key)
    {
        int probe = hash1(key);
        int chk = probe;
        int i = 0;

        while (array[(probe + (i * i)) % m] != NULL)
        {
            if (((probe + i * i) % m == chk) && (i != 0))
            {
                break;
            }

            i++;
        }

        if (((probe + i * i) % m == chk) && (i != 0))
        {
            return;
        }

        array[(probe + i * i) % m] = key;
    };

    void insertdh(int key)
    {
        int probe = hash1(key);
        int probe2 = hash2(key);

        int chk = probe;
        int i = 0;

        while (array[((probe + i * (probe2)) % m)] != NULL)
        {
            if (((probe + i * (probe2)) % m == chk) && (i != 0))
            {
                return;
            }

            i++;
        }

        array[(probe + i * (probe2)) % m] = key;
    };

    void deletelp(int key)
    {

        int probe = hash1(key);
        int chk = probe;
        int i = 0;

        while ((array[(probe + i) % m] != NULL) && (array[(probe + i) % m] != key))
        {
            if (((probe + i) % m == chk) && (i != 0))
            {
                return;
            }

            i++;
        }

        if (((probe + i) % m == NULL))
        {
            return;
        }

        array[(probe + i) % m] = deleted;
    };

    void deleteqp(int key)
    {

        int probe = hash1(key);
        int chk = probe;
        int i = 0;

        while ((array[(probe + i * i) % m] != NULL) && (array[(probe + i * i) % m] != key))
        {
            if (((probe + i * i) % m == chk) && (i != 0))
            {
                return;
            }

            i++;
        }

        if (((probe + i * i) % m == NULL))
        {
            return;
        }

        array[(probe + i * i) % m] = deleted;
    };
    void deletedh(int key)
    {
        int probe = hash1(key);
        int probe2 = hash2(key);

        int chk = probe;
        int i = 0;

        while ((array[((probe + i * (probe2)) % m)] != NULL) && array[((probe + i * (probe2)) % m)] != key)
        {
            if (((probe + i * (probe2)) % m == chk) && (i != 0))
            {
                return;
            }

            i++;
        }

        if (((probe + i * (probe2)) % m) % m == NULL)
        {
            return;
        }

        array[(probe + i * (probe2)) % m] = deleted;
    };

    bool searchlp(int key)
    {
        int probe = hash1(key);
        int chk = probe;
        int i = 0;

        while (array[(probe + i) % m] != NULL)
        {
            if (((probe + i) % m == chk) && (i != 0))
            {
                break;
            }

            if (array[(probe + i) % m] == key)
            {
                return true;
            }

            i++;
        }

        return false;
    };

    bool searchqp(int key)
    {

        int probe = hash1(key);
        int chk = probe;
        int i = 0;

        while (array[(probe + i * i) % m] != NULL)
        {
            if (((probe + i * i) % m == chk) && (i != 0))
            {
                break;
            }

            if (array[(probe + i * i) % m] == key)
            {
                return true;
            }

            i++;
        }

        return false;
    };

    bool searchdh(int key)
    {
        int probe = hash1(key);
        int probe2 = hash2(key);

        int chk = probe;
        int i = 0;

        while (array[((probe + i * (probe2)) % m)] != NULL)
        {
            if (((probe + i * (probe2)) % m == chk) && (i != 0))
            {
                return false;
            }
            if (array[(probe + i * (probe2)) % m] == key)
            {
                return true;
            }

            i++;
        }

        return false;
    };
};

void display(openhash hash)
{
    int i = 0;
    while (i < hash.m)
    {
        if ((hash.array[i] != NULL) && (hash.array[i] != hash.deleted))
            cout << hash.array[i] << " ";
        i++;
    }
}

int main()
{
    openhash data(5);
    data.insertlp(1);
    data.insertlp(2);
    data.insertlp(3);
    data.insertlp(40);
    data.insertlp(20);
    data.deletelp(20);
    display(data);
    cout << endl
         << data.searchlp(2) << "," << data.searchlp(20) << endl;

    openhash data2(5);
    data2.insertqp(1);
    data2.insertqp(2);
    data2.insertqp(3);
    data2.insertqp(40);
    data2.insertqp(20);
    data2.deleteqp(20);
    display(data2);
    cout << endl
         << data2.searchqp(2) << "," << data2.searchqp(20) << endl;

    openhash data3;
    data3.insertdh(1);
    data3.insertdh(2);
    data3.insertdh(3);
    data3.insertdh(40);
    data3.insertdh(20);
    data3.deletedh(20);
    display(data3);
    cout << endl
         << data3.searchdh(2) << "," << data3.searchdh(20) << endl;

    return 0;
}

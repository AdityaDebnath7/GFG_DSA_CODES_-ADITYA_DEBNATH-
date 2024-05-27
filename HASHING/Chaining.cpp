#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

// collision handling in hashing .
// CHAINING

class myhash
{
public:
     int bucket;
     list<int> *table;

     myhash(int b)
     {
          bucket = b;
          table = new list<int>[b];
     }

     void insert(int key)
     {
          int i = key % bucket;

          table[i].push_back(key);
     };

     void del(int key)
     {
          int i = key % bucket;
          table[i].remove(key);
     };

     bool search(int key)
     {
          int i = key % bucket;
          for (auto x : table[i])
          {
               if (x == key)
               {
                    return true;
               }
          }
          return false;
     };
};

int main()
{
     myhash hash(7);

     hash.insert(70);
     hash.insert(71);
     hash.insert(9);
     hash.insert(56);
     hash.insert(72);
     hash.insert(6);
     hash.insert(20);
     hash.insert(27);

     hash.del(56);

     cout << hash.search(27) << endl;
     cout << hash.search(71) << endl;
     cout << hash.search(9) << endl;
     cout << hash.search(20) << endl;
     cout << hash.search(41) << endl;
     return 0;
}
#include <iostream>
#include <vector>

using namespace std;
    

     vector <int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int> array(hashSize);
        
        for(int j=0;j<sizeOfArray;j++){
          int key=arr[j];
        int m= hashSize;
           
        int probe = key%hashSize;
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
    }
    return array;
    
    }

int main() {
 

 vector <int> a(4);
 a[1]=4;
 a[2]=2;
 a[0]=0;
a[3]=8;

for (int i = 0; i <4 ; i++)
{
   a[i];
   
}





     return 0 ;
}
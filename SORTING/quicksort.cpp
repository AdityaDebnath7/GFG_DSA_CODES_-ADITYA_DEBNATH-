#include <iostream>
using namespace std;

int partitionlomuto(int arr[], int l,int h)
{

    // pivot is consider the last element of the array this function put all elemets less than pivot on left and all elememts greater than pivot on right and return the correct index of pivot

    int i = l-1, j = 0;
    int p = h;

    while (j < (h+1))
    {
        if (arr[j] < arr[p])
        {
            i++;
            swap(arr[i], arr[j]);
            j++;
        }

        if (arr[j] > arr[p])
        {
            j++;
        }
    }
    i++;
    swap(arr[i], arr[p]);
    p = i;
    return p;
}



int hoarespartition(int arr[], int l, int h)
{   
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}




int main()
{

 int arr[]={5,3,8,4,2,7,1,10};

cout<<hoarespartition(arr,0,7);cout<<endl;
int i=0;

while (i<8)
{
    cout<<arr[i]<<" ";
    i++;

}

    return 0;
}
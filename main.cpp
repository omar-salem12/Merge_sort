#include <iostream>

using namespace std;


void Merge(int arr[],int st,int mid,int en) {

    int* out = new int[en - st + 1];
     int index = 0;

     int i = st,j = mid+1;


     while(i<=mid && j<=en) {

        if(arr[i] <= arr[j])
               out[index++] = arr[i++];

        else
           out[index++] = arr[j++] ;
     }

     while(i <= mid)
        out[index++] = arr[i++];

    while(j<=en)
        out[index++] = arr[j++];

    for(int k =st;k<=en;k++) {

        arr[k] = out[k-st];

    }

    delete [] out;
}


void mergeSort(int arr[],int st,int en) {

      int mid = (st+en)/2;


      if(st == en) return;

      mergeSort(arr,st,mid);
      mergeSort(arr,mid+1,en);
      Merge(arr, st, mid, en);


}


int main()
{

   int arr[] = {9,7,5,3,8};

    mergeSort(arr,0,4);

    for(int i =0;i<5;i++)
    {
      cout <<arr[i] <<endl;
    }

    return 0;
}

//Vedant Modi
//20BCE2126
#include<iostream>
#include<array>
using namespace std;

void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low, int high)
{
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low; j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);

}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main(void)
{
    int m,j;
    cout<<"Input the total no. of players :";
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++)
    {
        cout<<"Player "<<i+1<<" score :";
        cin>>arr[i];
    }
    int n = m-1;
    quicksort(arr, 0, n);

    int kk=sizeof(arr) / sizeof(arr[0]);

    cout<<"\nWinner score :"<<arr[kk-1];
    cout<<"\nNext winner score :"<<arr[kk-2];
    cout<<"\nWorst player :"<<arr[0];
    cout<<"\nnext worst player :"<<arr[1];


    return 0;
}







// Question 2
/*
#include <iostream>
using namespace std;
int merge(int arr[], int temp[], int left, int mid, int right) {
   int i, j, k;
   int count = 0;
   i = left;
   j = mid;
   k = left;
   while ((i <= mid - 1) && (j <= right)) {
      if (arr[i] <= arr[j]){
      temp[k++] = arr[i++];
      } else {
         temp[k++] = arr[j++];
         count += (mid - i);
      }
   }
   while (i <= mid - 1)
      temp[k++] = arr[i++];
   while (j <= right)
      temp[k++] = arr[j++];
   for (i=left; i <= right; i++)
      arr[i] = temp[i];
   return count;
}
int mergeSort(int arr[], int temp[], int left, int right){
   int mid, count = 0;
   if (right > left) {
      mid = (right + left)/2;
      count = mergeSort(arr, temp, left, mid);
      count += mergeSort(arr, temp, mid+1, right);
      count += merge(arr, temp, left, mid+1, right);
   }
   return count;
}
int arrInversion(int arr[], int n) {
   int temp[n];
   return mergeSort(arr, temp, 0, n - 1);
}
int main() {
   int m,j;
    cout<<"Input the total no. of numbers :";
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++)
    {

        cin>>arr[i];

    }
   cout << "Number of inversions are "<< arrInversion(arr, m);
}

*/

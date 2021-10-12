/*
Vedant Modi
20BCE2126
Nth smallest number
*/
#include <algorithm>
#include <iostream>
using namespace std;
int partition(int *a,int start,int end)
{
    int pivot=a[end];
    int P_index=start;
    int i,t;
    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;


     return P_index;
 }
 void Quicksort(int *a,int start,int end)
 {
    if(start<end)
    {
         int P_index=partition(a,start,end);
             Quicksort(a,start,P_index-1);
             Quicksort(a,P_index+1,end);
    }
}
int nthsmallest(int data[], int k, int n)
{
    Quicksort(data,0, k-1);
    return data[n - 1];
}
int main()
{
    int sizeofarray,data[100],n;
    cin >> sizeofarray;
    for (int i = 0; i < sizeofarray; ++i)
    {
        cin >> data[i];
    }
    cout<<"nth number";
    cin>>n;
    int k = sizeofarray;
    cout << "N'th smallest element is " << nthsmallest(data, k, n);
    return 0;
}

//Vedant Modi
//20BCE2126
#include <bits/stdc++.h>
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
int findMaximum(int arr[], int low, int high)
{


	int max = arr[low];
	int i;
	for (i = low + 1; i <= high; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else
			break;
	}
	return max;
}


int main()
{
    int x,y,z;
    cout<<"Max Element using Iteration\n\n\n";
    cout<<"Enter the size of the array: ";
    cin>>y;
    int arr[y];
    cout<<"\n\nEnter the Elements in the array: ";
	for(x=0;x<y;x++)
    {
        cout<<"\n Enter the "<<"Element "<<x+1<<" : ";
        cin>>z;
        arr[x]=z;
    }
    Quicksort(arr,0,y-1);


	cout << "The maximum element is " << findMaximum(arr, 0, y-1);
	return 0;
}

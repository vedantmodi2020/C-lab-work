#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int N,i,j;
    int codd=0, ceven=0;
    int A[N],Sorted[10], OddQ[10], Even[10];
    cout<<"Enter number of customers"<<endl;
    cin>>N;
    cout<<"Enter last two digits of bill number";
    for(i=0;i<=N-1;i++)
    {
        cin>>A[i];
        cout<<endl;
    }
    for (i = 0; i < N-1; i++)
    {
        for (j = 0; j < N-i-1; j++)
        {
            if (A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    for(i=0;i<N;i++)
        cout<<"Sorted:"<<A[i]<<endl;
    for(i=0;i<N;i++)
    {
        if(A[i]%2==0)
        {
            Even[ceven]=A[i];
            ceven++;
        }
        else
        {
            OddQ[codd]=A[i];
            codd++;
        }
    }
for(int k=0;k<codd;k++)
    cout<<"Odd_Q:"<<OddQ[k]<<endl;
for(int l=0;l<ceven;l++)
    cout<<"Even_Q:"<<Even[l]<<endl;
}

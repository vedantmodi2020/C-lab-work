#include <iostream>
#include<stdio.h>

using namespace std;


//vedant modi 20BCE2126

int main()
{
    int N,i,j;
    int codd=0, ceven=0;
    int A[N],Sorted[10], OddQ[10], Even[10],xp[100];
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
cout<<"Sorted:";
    for(i=0;i<N;i++)
        cout<<A[i]<<",";
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
cout<<"\n"<<"Odd:";
for(int k=0;k<codd;k++)
    cout<<OddQ[k]<<",";
cout<<"\n"<<"Even:";
for(int l=0;l<ceven;l++)
    cout<<Even[l]<<",";
int vv=sizeof(OddQ);
int vvv=sizeof(Even);
if (vv/2>vvv)
{
    for(int ii=0;ii<vvv;ii++)
    {
        xp[ii]=vv[ii];
        xp[ii+1]=vvv[ii];
        xp[ii+2]=vvv[ii+1];
    }
    }
}




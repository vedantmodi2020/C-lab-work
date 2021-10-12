/*
Vedant Modi
20BCE2126
*/

#include<iostream>
using namespace std;
int main()
{
int factorial(int);
int fact,number;
cout<<"Enter any number: ";
cin>>number;
fact=factorial(number);
cout<<"Factorial of a number is: "<<fact<<endl;
return 0;
}
int factorial(int n)
{
if(n<0)
return(-1);
if(n==0)
return(1);
else
{
return(n*factorial(n-1));
}
}

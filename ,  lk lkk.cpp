#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
cout<<"Program to Swap 2 Numbers Without Using Thrid variable";
cout<<"Enter the First Number: ";
int x,y;
cin>> x;
cout<<"\nEnter the Second Number: ";
cin>> y;

x=x*y;
x=x/y;
y=x/y;

cout<<"\n Numbers After Swapping \n";
cout<<"X="<<x<<" Y="<<y;
return 0;

#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main ()
{
    int n ;
    cout<<"20BCE2126 VEDANT MODI\n\n";
    cout<<"Enter the limit of the Fibonacci Number: ";
    cin>>n;
    cout << fibonacci(n);
    getchar();
    return 0;
}

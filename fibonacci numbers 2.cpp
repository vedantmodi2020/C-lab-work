
#include <bits/stdc++.h>
using namespace std;


double PHI = 1.6180339;
int f[6] = { 0, 1, 1, 2, 3, 5 };
int fib (int n)
{
	if (n < 6)
		return f[n];
	int t = 5, fn = 5;

	while (t < n) {
		fn = round(fn * PHI);
		t++;
	}

	return fn;
}
int main()
{
	int n ;
	cout<<"20BCE2126 VEDANT MODI\n\n";
	cout<<"Enter the fibonacci number :";
	cin>>n;

	cout << n << "th Fibonacci Number = "
		<< fib(n) << endl;

	return 0;
}

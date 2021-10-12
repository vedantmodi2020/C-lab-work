#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t>0)
	{   string s1,s2;
	  cin>>s1;
	  cin>>s2;
	  int m=0;
	  int n=0;
	  for(int i=0;s1[i]!='\0';i++)
	  {
	      n=n+1;
	  }
	  for(int i=0;s2[i]!='\0';i++)
	  {
	      m=m+1;
	  }
	  int k=0;

	  int q;
	  for(int i=n-1;i>=0;i--)
	  {
	      q=s1[i]-48;
	      k=k+pow(2,n-1-(i))*q;

	  }
	  int l=0;
	   for(int i=m-1;i>=0;i--)
	  {
	      q=s2[i]-48;
	      l=l+pow(2,m-1-(i))*q;

	  }
	  cout<<l*k<<endl;





	    t=t-1;

	}
	return 0;
}

#include <iostream>
using namespace std;
int main() {
  int n1=0,n2=1,n3,i,num;
  cout<<"20BCE2126 VEDANT MODI\n\n";
 cout<<"Enter the number of elements: ";
 cin>>num;
for(i=1;i<num;++i)
 {
  n3=n1+n2;

  n1=n2;
  n2=n3;
 }
 cout<<"\n";
 cout<<" "<<n2<<" ";

   return 0;
   }

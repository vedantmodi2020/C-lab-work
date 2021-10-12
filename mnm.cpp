#include<iostream>
#include<cmath>
using namespace std;



int main()
{
    int a1,b1,c1, c=0, temp1;
    double temp, maxar=0;

    int n;
    cin>>n;
    n=n*2;

    int x[n][2];
    int cod[n][3][2];

    for(int i=0;i<n;i++){
        cin>>x[i][0]>>x[i][1];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(x[j][1]>x[j+1][1]){
                temp1 = x[j][1];
                x[j][1] = x[j+1][1];
                x[j+1][1] = temp1;

                temp1 = x[j][0];
                x[j][0] = x[j+1][0];
                x[j+1][0] = temp1;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if(x[j][0]>x[j+1][0]){
                temp1 = x[j][0];
                x[j][0] = x[j+1][0];
                x[j+1][0] = temp1;

                temp1 = x[j][1];
                x[j][1]= x[j+1][1];
                x[j+1][1] = temp1;
            }
        }
    }



    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                a1=x[i][0]*x[j][1]-x[j][0]*x[i][1];
                b1=x[j][0]*x[k][1]-x[k][0]*x[j][1];
                c1=x[k][0]*x[i][1]-x[i][0]*x[k][1];
                temp = abs((a1+b1+c1)/2.0);

                if(maxar<temp){
                    maxar=temp;
                    c=1;
                    cod[c][0][0]=x[i][0];
                    cod[c][0][1]=x[i][1];
                    cod[c][1][0]=x[j][0];
                    cod[c][1][1]=x[j][1];
                    cod[c][2][0]=x[k][0];
                    cod[c][2][1]=x[k][1];
                }
                else if(maxar==temp){
                    c++;
                    cod[c][0][0]=x[i][0];
                    cod[c][0][1]=x[i][1];
                    cod[c][1][0]=x[j][0];
                    cod[c][1][1]=x[j][1];
                    cod[c][2][0]=x[k][0];
                    cod[c][2][1]=x[k][1];
                }
            }
        }
    }




//cout<<maxar<<endl;
    for(int j=1; j<=c; j++){

        for(int i=0; i<3; i++){
            cout<<cod[j][i][0]<<"\t"<<cod[j][i][1]<<endl;
        }
    }

}

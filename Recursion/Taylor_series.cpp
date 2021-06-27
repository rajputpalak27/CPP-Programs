#include<bits/stdc++.h>
#include<iostream>
using namespace std;

double taylor_series(int x,int n){
    static double s;
    if(n==0){
        return s;
    }else{
        s=1+x*s/n;
        return taylor_series(x,(n-1));
    }
}

int main(){
int x,n;
cout<<endl<<"Enter the exponent value: "<<endl;
cin>>x;
cout<<endl<<"Enter the Factorial value: "<<endl;
cin>>n;

double res;
res=taylor_series(x,n);
cout<<"The value is: "<<res<<endl;

return 0;
}


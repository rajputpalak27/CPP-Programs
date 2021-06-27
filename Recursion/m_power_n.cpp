#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int exponential(int m,int n){
    if(n==0){
        return 1;
    }else{
        if(n%2==0){
            return exponential(m*m,n/2);
        }else{
            return m*exponential(m*m,(n-1)/2);
        }
    }
}

int main(){
int m,n;
cout<<"Enter the coefficient and exponent value: "<<endl;
cin>>m>>n;

int res;
res=exponential(m,n);
cout<<"The value is: "<<res<<endl;

return 0;
}


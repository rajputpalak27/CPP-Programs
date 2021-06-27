#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int nCr(int n,int r){
    if(n==r || r==0){
        return 1;
    }else{
        return nCr(n-1,r-1)+nCr(n-1,r);
    }
}

int main(){
int n,r;
cout<<"Enter the value of n and r: "<<endl;
cin>>n>>r;
int res;

res=nCr(n,r);
cout<<endl<<"The value of nCr is: "<<res<<endl;

return 0;
}



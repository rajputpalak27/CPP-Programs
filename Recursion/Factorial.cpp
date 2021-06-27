#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fact(int n){
    if(n==0){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}

int main(){
int n;
cout<<"Enter the number you want to find Factorial for: "<<endl;
cin>>n;
int res=1;

res=fact(n);
cout<<endl<<"The Factorial of given number is: "<<res<<endl;

return 0;
}


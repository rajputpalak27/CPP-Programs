#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }else{
        return fibonacci(n-2)+fibonacci(n-1);
    }
}

int m[10];

int fibonacci_memoization(int n){

    if(n<=1){
        m[n]=n;
        return n;
    }else{
        if(m[n-2]==-1){
            m[n-2]=fibonacci_memoization(n-2);
        }
        if(m[n-1]==-1){
            m[n-1]=fibonacci_memoization(n-1);
        }

        m[n]=m[n-2]+m[n-1];
        return m[n-2]+m[n-1];
    }
}

int main(){
int n;
cout<<"Enter the number you want to find Fibonacci for: "<<endl;
cin>>n;
int res;

res=fibonacci(n);
cout<<endl<<"The Factorial of given number is: "<<res<<endl;

for(int i=0;i<10;i++)
 m[i]=-1;

res=fibonacci_memoization(n);
cout<<endl<<"The Factorial of given number is: "<<res<<endl;

return 0;
}



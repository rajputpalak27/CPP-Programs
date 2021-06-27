#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }else{
        return sum(n-1)+n;
    }
}

int main(){
int n;
cout<<"Enter the number you want to sum up till: "<<endl;
cin>>n;
int res;

res=sum(n);
cout<<endl<<"The sum of the N Natural Numbers is: "<<res<<endl;

return 0;
}

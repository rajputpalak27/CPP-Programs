#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE FOR FINDING MAXIMUM AND MINIMUM ARRAY ELEMENT

int min_ele(int arr[],int n){
int f=arr[0];

for(int i=1;i<n;i++){
if(arr[i]<f){
f=arr[i];
}
}
return f;
}


int max_ele(int arr[],int n){
int f=arr[0];

for(int i=1;i<n;i++){
if(arr[i]>f){
f=arr[i];
}
}
return f;
}


int main(){

int n;
cout<<"Enter the size of the array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements of an array"<<endl;
for(int i=0;i<n;i++){
cin>>arr[i];
cout<<endl;
}

cout<<endl<<"The minimun element in the array is :"<<min_ele(arr,n)<<endl;

cout<<endl<<"The minimun element in the array is :"<<max_ele(arr,n)<<endl;


return 0;
}

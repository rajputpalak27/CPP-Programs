#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE FOR REVERSING ARRAY IN SAME ARRAY

int main(){

int n;
cout<<"Enter the size of the array :"<<endl;
cin>>n;

int arr[n];
cout<<"Enter the elements of an array :"<<endl;

for(int i=0;i<n;i++){
cin>>arr[i];
cout<<endl;
}

for(int i=0;i<n;i++){
if(i<=(n/2)){
int temp=arr[i];
arr[i]=arr[n-(i+1)];
arr[n-(i+1)]=temp;
}
}

cout<<"Reversed array is :"<<endl;

for(int i=0;i<n;i++){
cout<<arr[i];
}

return 0;
}

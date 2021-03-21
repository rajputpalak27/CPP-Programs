#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO LEFT ROTATE THE ELEMENT OF ARRAY BY 1

void left_rotate(int arr[],int n){
int temp;
temp=arr[0];
for(int i=0;i<n;i++){
arr[i]=arr[i+1];
}
arr[n-1]=temp;

cout<<"Left Rotated array is :"<<endl;

for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
}


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

//LEFT ROTATE
left_rotate(arr,n);

return 0;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO RIGHT ROTATE THE ELEMENT OF ARRAY BY 1


void right_rotate(int arr[],int n){
int temp;
temp=arr[n-1];
for(int i=n-1;i>=0;i--){
arr[i]=arr[i-1];
}
arr[0]=temp;

cout<<endl<<"Right Rotated array is :"<<endl;

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

//RIGTH ROTATE
right_rotate(arr,n);

return 0;
}

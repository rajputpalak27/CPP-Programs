#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM TO ARRANGE ALL NEGATIVE NUMBERS O ONE SIDE OF ARRAY

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

int j=0,temp;

for(int i=0;i<n;i++){
if(arr[i]<0){
  if(i!=j){
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
  j++;
}
}


for(int i=0;i<n;i++){
cout<<endl<<arr[i];
}

return 0;
}

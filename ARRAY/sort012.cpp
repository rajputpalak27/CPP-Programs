#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE FOR SORTING THE ARRAY WITH 0 1 2 ONLY WITHOUT USING ANY SORTING ALGORITHM

int main()
{

int arr[]={0,2,1};
int temp;
for(int i=0;i<3;i++){
if(arr[i]>arr[i+1]){
temp=arr[i];
arr[i]=arr[i+1];
arr[i+1]=temp;
}
}

cout<<"Sorted array is :"<<endl;
for(int i=0;i<3;i++){
cout<<arr[i]<<" ";
}

return 0;
}

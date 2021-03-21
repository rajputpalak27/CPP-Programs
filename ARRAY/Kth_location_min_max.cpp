#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO FIND THE MINIMUM AND MAXIMUM NUMBER UPTILL THE Kth LOCATION IN ARRAY

int main(){

int n,k;
cout<<"Enter the size of the array :"<<endl;
cin>>n;

cout<<"Enter the location of the array to find minimum maximum value upto :"<<endl;
cin>>k;

int arr[n];
cout<<"Enter the elements of an array :"<<endl;

for(int i=0;i<n;i++){
cin>>arr[i];
}

int min_ele,max_ele;

min_ele = arr[0];
max_ele = arr[0];

for(int i=1;i<k;i++){
if(arr[i]<min_ele)
{
min_ele=arr[i];
}
}



for(int i=1;i<k;i++){
if(arr[i]>max_ele)
{
max_ele=arr[i];
}
}

cout<<"The minimun Kth location element is :"<<min_ele<<endl;
cout<<"The maximum Kth location element is :"<<max_ele<<endl;

}

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

 toh(int n,int A,int B,int C){
 if(n>0){
        toh(n-1,A,C,B);
        cout<<"("<<A<<","<<C<<")"<<endl;
        toh(n-1,B,A,C);
    }
}

int main(){
toh(4,1,2,3);
return 0;
}



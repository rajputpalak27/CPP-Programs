#include<bits/stdc++.h>
using namespace std;
//MATHEMATICAL APPROACH using
//n*(n=1)/2
//a=(n-l*(l+1)/2/(l+1)

int main(){
    int n;
    cout<<"Enter the value of N :"<<endl;
    cin>>n;

    int length=0,sum=0;

    for(int i=1;sum<n;i++){
        sum=sum+i;
        length++;
    }

    int count=0;
    float a;

    for(int i=1;i<length;i++){
        a=(n*1.0 - i * ( i + 1 )/2)/(i+1);
        if(a-int(a)==0.0){
            count+=1;
        }
    }

    cout<<"No of ways :"<<count<<endl;

}

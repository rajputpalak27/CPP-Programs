#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    int n[t],m[t];
    
    for(int i=0;i<t;i++){
        cin>>n[i]>>m[i];
    }

    for(int i=0;i<t;i++){
       int flag=0,r=1;
       while(flag==0){
           if((r*n[i])%m[i]==0){
               cout<<r<<endl;
               flag=1;
           }
            r=r+1;
       }
    }

    return 0;
}

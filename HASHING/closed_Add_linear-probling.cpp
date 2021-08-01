#include<bits/stdc++.h>
using namespace std;
#define size 10

int hs(int key)
{
    return key%size;
}

int linearProbing(int ht[],int key){
    int index;
    index=hs(key);
    int i=0;
    while(ht[(index+i)%size]!=0){
        i++;
    }
    return (index+i)%size;
}

int insert(int ht[],int key){
    int index;
    index=hs(key);

    if(ht[index]!=0){
        index=linearProbing(ht,key);
    }

    ht[index]=key;
    cout<<"done"<<endl;

}

int search(int ht[],int key){
    int index;
    index=hs(key);
    int i=0;
    while(ht[(index+i)%size]!=key){
        i++;
    }

    return (index+i)%size;
}

int main(){
    int ht[size]={0};

    insert(ht,24);
    insert(ht,34);
    insert(ht,2);
    insert(ht,11);

    if(search(ht,19)==0){
        cout<<"Element Not Found"<<endl;
    }else{
       cout<<endl<<"Element found at :"<<search(ht,19);
    }


    return 0;
}

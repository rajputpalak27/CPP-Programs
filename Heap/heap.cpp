#include<bits/stdc++.h>
using namespace std;
void insert(int heap[],int n){
   int i,last;
   i=n;
   last=heap[i];

   while(i>1 && last>heap[i/2]){
    heap[i]=heap[i/2];
    i=i/2;
   }
   heap[i]=last;
}


void del(int heap[],int n){
  int last,val,i,j;

  val=heap[1];
  heap[1]=heap[n];
  heap[n]=val;

  i=1;
  j=2*1;

  while(j<n-1){
    if(heap[j+1]>heap[j]){
        j=j+1;
    }
    if(heap[j]>heap[i]){
        int temp;
        temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
        i=j;
        j=2*j;
    }else{
        break;
    }
  }

    cout<<endl<<"DELETED VALUE \t"<<val<<" ";
}


int main()
{
    int n;
    cout<<"Enter the elements you want in the heap"<<endl;
    cin>>n;
    int heap[n+1];
    heap[0]=0;

    for(int i=1;i<=n;i++){
            cin>>heap[i];
    }

    for(int i=2;i<=n;i++){
        insert(heap,i);
    }

    for(int i=1;i<=n;i++){
            cout<<heap[i]<<" ";
    }


     for(int i=n-1;i>=1;i--){
        del(heap,i);
    }

    cout<<"\n";
      for(int i=1;i<=n;i++){
            cout<<heap[i]<<" ";
    }

    return 0;
}

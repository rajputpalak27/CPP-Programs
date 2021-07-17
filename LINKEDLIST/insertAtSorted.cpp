#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void insert(int n){
    int ele;
    cout<<"Enter the Element 1: ";
    cin>>ele;

    struct Node *new_node,*last;

    first=new Node;
    first->data=ele;
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        cout<<"Enter the Element "<<i+1<<": ";
        cin>>ele;
        new_node=new Node;
        new_node->data=ele;
        new_node->next=NULL;
        last->next=new_node;
        last=new_node;
    }
}


void insertAtSorted(struct Node *f,int e){
  struct Node *new_node,*q=NULL;
  new_node=new Node;
  new_node->data=e;
  new_node->next=NULL;

  if(first==NULL){
    first=new_node;
  }else{
    while(f && f->data<e){
        q=f;
        f=f->next;
    }
    if(f==first){
        new_node->next=first;
        first=new_node;
    }else{
        new_node->next=q->next;
        q->next=new_node;
    }
  }
}

void display(struct Node *f){
    while(f!=NULL){
            cout<<f->data<<" ";
            f=f->next;
    }
}


int main(){

    int n,e;
    cout<<"Enter the elements you want in linked list: ";
    cin>>n;

    insert(n);

    cout<<"Enter the Element :"<<endl;
    cin>>e;

    insertAtSorted(first,e);

    display(first);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void insert1(int n){
    struct Node *new_node, *last;
    int ele;
    cout<<"Enter the element 1: ";
    cin>>ele;
    first=new Node;
    first->data=ele;
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        cout<<"Enter the element "<<i+1<<": ";
        cin>>ele;
        new_node=new Node;
        new_node->data=ele;
        new_node->next=NULL;
        last->next=new_node;
        last=new_node;
    }
}

void insert2(int n){
    struct Node *new_node, *last;
    int ele;
    cout<<"Enter the element 1: ";
    cin>>ele;
    second=new Node;
    second->data=ele;
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++){
        cout<<"Enter the element "<<i+1<<": ";
        cin>>ele;
        new_node=new Node;
        new_node->data=ele;
        new_node->next=NULL;
        last->next=new_node;
        last=new_node;
    }
}

void mergeList(struct Node *l1,struct Node *l2){
    struct Node *last;

    if(l1->data<l2->data){
        third=last=l1;
        l1=l1->next;
        last->next=NULL;
    }else{
        third=last=l2;
        l2=l2->next;
        last->next=NULL;
    }

    while(l1 && l2){
        if(l1->data<l2->data){
            last->next=l1;
            last=l1;
            l1=l1->next;
            last->next=NULL;
        }else{
            last->next=l2;
            last=l2;
            l2=l2->next;
            last->next=NULL;
        }
    }

    if(l1){
        last->next=l1;
    }

    if(l2){
        last->next=l2;
    }
}

void display(struct Node *f){
    while(f){
        cout<<f->data<<" ";
        f=f->next;
    }
}


int main(){

    int n1,n2;
    cout<<"Enter the no of elements you want in linked list 1"<<endl;
    cin>>n1;
    insert1(n1);

    cout<<endl<<"Enter the no of elements you want in linked list 2"<<endl;
    cin>>n2;
    insert2(n2);

    mergeList(first,second);

    cout<<endl<<"The Linked List is :"<<endl;
    display(third);
    cout<<endl<<endl;

    return 0;


}

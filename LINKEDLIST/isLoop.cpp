#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void insert(int n){
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

void isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        if(q!=NULL){
            q=q->next;
        }
    }while(q && p && p!=q);

    if(p==q){
        cout<<"Loop Exists"<<endl;
    }else{
        cout<<"Loop does not Exists"<<endl;
    }
}

void display(struct Node *f){
    while(f){
        cout<<f->data<<" ";
        f=f->next;
    }
}

int main(){
    int n;
    cout<<"Enter no of elements you want in the linked list"<<endl;
    cin>>n;

    insert(n);

    struct Node *l1, *l2;
    l1=first;
    l2=first->next->next->next;               //for the linked list having four nodes
    l2->next=l1;


    isLoop(first);



    return 0;
}

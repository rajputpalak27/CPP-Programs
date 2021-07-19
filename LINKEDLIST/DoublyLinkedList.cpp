#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev,*next;
}*first=NULL;

void create(struct Node *f,int n){
    int ele;
    cout<<"Enter element 1:";
    cin>>ele;

    struct Node *new_node,*last=new Node;

    first=new Node;
    first->data=ele;
    first->prev=NULL;
    last=first;

    for(int i=1;i<n;i++){
        cout<<"Enter element "<<i+1<<" :";
        cin>>ele;

        new_node=new Node;
        new_node->data=ele;
        new_node->next=NULL;
        new_node->prev=last;
        last->next=new_node;
        last=new_node;
    }
}

void insertAt(struct Node *f,int n){
    int ele,pos;
    cout<<"Enter the element and position you want to insert element at :"<<endl;
    cin>>ele;
    cin>>pos;

    struct Node *new_node=new Node;
    new_node->data=ele;

    if(pos==0){
        new_node->next=first;
        new_node->prev=NULL;
        first->prev=new_node;
        first=new_node;

    }else if(pos>0 && pos<=n){
        for(int i=0;i<pos-1;i++){
            f=f->next;
        }

        new_node->next=f->next;
        new_node->prev=f;
        if(f->next){
            f->next->prev=new_node;
        }
        f->next=new_node;

    }else{
        cout<<"INVALID INDEX"<<endl;
    }
}

void deleteFrom(struct Node *f,int n){
    int pos;
    cout<<"Enter the position you want to delete element from ";
    cin>>pos;

    if(pos==1){
        f=first;
        first=first->next;
        first->prev=NULL;
        delete f;
    }else if(pos>1 && pos<=n){
         for(int i=0;i<pos-1;i++){
        f=f->next;
        }
        f->prev->next=f->next;
        f->next->prev=f->prev;
        delete f;
    }else{
        cout<<"INVALID INDEX"<<endl;
    }
}

void reverseList(struct Node *f){
    struct Node *temp;

    while(f){
        temp=f->next;
        f->next=f->prev;
        f->prev=temp;
        f=f->prev;
        if(f!=NULL && f->next==NULL){
            first=f;
        }
    }
}

void display(struct Node *f){
    while(f){
        cout<<f->data<<" ";
        f=f->next;
    }
    cout<<endl;
}

int main(){

    int n;
    cout<<"Enter elements you want in doubly linked list"<<endl;
    cin>>n;

    create(first,n);
    cout<<endl;
    display(first);
    cout<<endl;

    insertAt(first,n);
    cout<<endl;
    display(first);
    cout<<endl;

    deleteFrom(first,n);
    cout<<endl;
    display(first);
    cout<<endl;

    reverseList(first);
    cout<<endl;
    cout<<"REVERSED LINKED LIST:"<<endl;
    display(first);
    cout<<endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void create(int n){
    int ele;
    cout<<"Enter element 1: ";
    cin>>ele;

    struct Node *new_node,*last;
    head=new Node;
    head->data=ele;
    head->next=head;
    last=head;

    for(int i=1;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>ele;

        new_node=new Node;
        new_node->data=ele;
        new_node->next=last->next;
        last->next=new_node;
        last=new_node;
    }
}

void insertAt(struct Node *h,int n){

    struct Node *new_node;
    int ele,pos;

    cout<<"Enter the element and position to be inserted at :"<<endl;
    cin>>ele;
    cin>>pos;
    cout<<endl;
    new_node=new Node;
    new_node->data=ele;

    if(pos==0){
        do{
            h=h->next;
        }while(h->next!=head);

        new_node->next=head;
        h->next=new_node;
        head=new_node;

    }else if(pos>0 && pos<=n){
        for(int i=0;i<pos-1;i++){
            h=h->next;
        }
        new_node->next=h->next;
        h->next=new_node;
    }else{
        cout<<"INVALID INDEX"<<endl;
    }
}


void deleteFrom(struct Node *h,int n){
    struct Node *temp=new Node;
    int pos;

    cout<<"Enter the position to delete element from :"<<endl;
    cin>>pos;

    if(pos==1){
        do{
            h=h->next;
        }while(h->next!=head);
        temp=head;
        head=head->next;
        h->next=head;
        delete temp;
    }else if(pos>1 && pos<=n){
        for(int i=0;i<pos-2;i++){
            h=h->next;
        }
        temp=h->next;
        h->next=temp->next;
        delete temp;

    }else{
        cout<<"INVALID INDEX"<<endl;
    }
}

void display(struct Node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=head);
}


int main(){

    int n;
    cout<<"Enter the n"<<endl;
    cin>>n;

    create(n);


    deleteFrom(head,n);
    cout<<endl;

    display(head);
    cout<<endl;

    return 0;
}

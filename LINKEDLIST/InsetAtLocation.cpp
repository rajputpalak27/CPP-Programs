#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO INSET ELEMENT AT END OF LINKEDLIST

struct Node{
int data;
struct Node *next;
}*first=NULL;

void insert_node(int n){

int ele;
cout<<"Enter the Element :";
cin>>ele;

struct Node *new_node,*last;
first=new Node;
first->data=ele;
first->next=NULL;
last=first;

for(int i=1;i<n;i++){
cout<<"Enter the Element "<<i+1<<" :";
cin>>ele;
new_node=new Node;
new_node->data=ele;
new_node->next=NULL;
last->next=new_node;
last=new_node;
}

}

void display(Node *f){
while(f!=NULL){
cout<<f->data<<" ";
f=f->next;
}
}


void insert_sorted(Node *f){
int ele;
cout<<"Enter the element to be inserted"<<endl;
cin>>ele;
Node *t=NULL,*new_node;
new_node=new Node;
new_node->data=ele;
new_node->next=NULL;

if(first==NULL){
first=new_node;
}
else{
while(f && f->data<ele){
t=f;
f=f->next;
}
if(f==first){
new_node->next=first;
first=new_node;
}else{
new_node->next=t->next;
t->next=new_node;
}
}

}


int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
insert_sorted(first);
insert_sorted(first);
display(first);
return 0;
}

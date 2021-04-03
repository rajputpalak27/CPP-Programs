#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE FOR DELETING LEMENT FROM SPECIFIED INDEX OF LINKEDLIST

struct Node{
int data;
struct Node *next;
}*first=NULL;

void insert(int n){
int ele;
cout<<"Enter Element 1: ";
cin>>ele;

struct Node *new_node,*last;

first=new Node;
first->data=ele;
first->next=NULL;
last=first;

for(int i=1;i<n;i++){
cout<<"Enter Element"<<i+1<<" : ";
cin>>ele;

new_node=new Node;
new_node->data=ele;
new_node->next=NULL;
last->next=new_node;
last=new_node;
}
}

void display(Node *f){
cout<<"------------------------------------"<<endl;
while(f){
cout<<f->data<<" | ";
f=f->next;
}
cout<<endl<<"------------------------------------"<<endl;
}


void delete_from(Node *f){
struct Node *t=NULL,*r;

int pos,value;
cout<<"Enter the position you want to delete element from"<<endl;
cin>>pos;

if(pos==1){
r=first;
first=first->next;
value=r->data;
delete r;
}

else{
for(int i=0;i<pos-1 && f;i++){
t=f;
f=f->next;
}
if(f){
t->next=f->next;
r=f;
value=r->data;
delete r;
}
}

}

int main()
{
int n;
cout<<"Enter the number of elements you want in the LINKEDLIST"<<endl;
cin>>n;

insert(n);
display(first);
delete_from(first);
display(first);

return 0;
}

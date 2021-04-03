#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO REMOVE AND DISPLAY DUPLICATES FROM LINKEDLIST

struct Node{
int data;
struct Node *next;
}*first=NULL;

void insert_node(int n){

int ele;
cout<<"Enter the Element 1 :";
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
cout<<"------------------------------------"<<endl;
while(f){
cout<<f->data<<" | ";
f=f->next;
}
cout<<endl<<"------------------------------------"<<endl;
}

void delete_duplicate(Node *f){
struct Node *t=f->next;

while(t!=NULL){
if(f->data!=t->data){
f=t;
t=t->next;
}
else{
  f->next=t->next;
  delete t ;
  t=f->next;
}
}
}


int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
display(first);
delete_duplicate(first);
display(first);

return 0;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO CREATE AND DISPLAY LINKEDLIST

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
cout<<"Enter the Element :";
cin>>ele;
new_node=new Node;
new_node->data=ele;
new_node->next=NULL;
last->next=new_node;
last=new_node;
}

}

void display(struct Node *f){
while(f!=NULL){
cout<<f->data<<" ";
f=f->next;
}
}


int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
display(first);
return 0;
}

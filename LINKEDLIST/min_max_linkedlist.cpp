#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO FIND MIN MAX ELEMENT OF LINKEDLIST

struct Node{
int data;
struct Node *next;
}*first=NULL;


//NODE CREATION
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
cout<<endl;
}


//DISPLAYING LINKEDLIST
void display(struct Node *f){

while(f!=NULL){
cout<<f->data<<" ";
f=f->next;
}
cout<<endl<<endl;
}


//FINDING MAX ELEMENT
void max_linked(struct Node *f){
int max=f->data;
while(f){
if(f->data>max){
max=f->data;
}
f=f->next;
}
cout<<"Maximum element of Linked List is "<<max<<endl;
}

//FINDING MIN ELEMENT
void min_linked(struct Node *f){
int min=f->data;
while(f){
if(f->data<min){
min=f->data;
}
f=f->next;
}
cout<<"Minimum element of Linked List is "<<min<<endl;
}
//MAIN FUNCTION
int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
display(first);
min_linked(first);
max_linked(first);

return 0;
}

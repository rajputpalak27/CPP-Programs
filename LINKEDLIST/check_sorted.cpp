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

void check_sorted(Node *f){

int value=-32768,flag=0;  //minimal value taken
while(f!=NULL){
if(f->data>value){
value=f->data;
f=f->next;
flag=1;
}
else{
flag=0;
  cout<<endl<<"LinkedList Not Sorted" <<endl;
  break;
 }
}
if(flag==1){
cout<<endl<<"LinkedList Sorted"<<endl;
}

}

int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
check_sorted(first);
display(first);
return 0;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO REVERSE AND DISPLAY LINKEDLIST

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

//USING SLIDING POINTERS
void reverse(Node *f){
Node *t1=NULL,*t2=NULL;
while(f!=NULL){
t2=t1;
t1=f;
f=f->next;
t1->next=t2;
}
first=t1;
}

//USING RECURSION
void recursion(Node *t,Node *f){
if(f){
    recursion(f,f->next);
    f->next=t;
}else{
    first=t;
}
}


int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
display(first);

reverse(first);
display(first);

recursion(NULL,first);
recursion(NULL,first); //called twice as it got reversed linkedlist as input
display(first);

return 0;
}

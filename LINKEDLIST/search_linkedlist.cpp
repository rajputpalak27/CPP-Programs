#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO SEARCH IN LINKEDLIST

struct Node{
int data;
struct Node *next;
}*first=NULL;

void insert_node(int n){

int ele;
cout<<"Enter the Element 1: ";
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

void search(Node *f){
int ele;
cout<<endl<<"Enter the element to be searched in linked list"<<endl;
cin>>ele;
int flag=0;
while(f){
if(ele==f->data){
cout<<"The element is present at :"<<f<<endl;
flag=1;
break;
}else{
    f=f->next;
}
}
if(flag==0){
    cout<<"The element is not present"<<endl;
}
}


int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
display(first);
search(first);
return 0;
}

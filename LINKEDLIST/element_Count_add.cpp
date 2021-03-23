
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//PROGRAM CODE TO CREATE AND DISPLAY LINKEDLIST

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


//COUNTING ELEMENTS IN LNKEDLIST
void count_node(struct Node *f){
int count=0;
while(f!=NULL){
count+=1;
f=f->next;
}
cout<<"The number of Elements in Linked list are :"<<count<<endl<<endl;
}


//ADDING ELEMENTS OF LINKEDLIST
void sum_node(struct Node *f){
int sum=0;
while(f!=NULL){
sum+=f->data;
f=f->next;
}
cout<<"The Sum of Elements in Linked list is :"<<sum<<endl<<endl;
}

//MAIN FUNCTION
int main(){
int n;
cout<<"Enter how many elements you want in the LinkedList :";
cin>>n;

insert_node(n);
display(first);
count_node(first);
sum_node(first);

return 0;
}

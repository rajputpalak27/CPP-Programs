#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*top=NULL;

void push(int data)
{
    struct Node *temp=new Node;
    if(temp==NULL){
        cout<<"Stack Overflow"<<endl;
    }else{
        temp->data=data;
        temp->next=top;
        top=temp;
    }
}

void pop(){
    struct Node *temp=new Node;

    int val;
    if(top==NULL){
         cout<<"Stack Underflow"<<endl;
    }else{
        temp=top;
        top=top->next;
        val=temp->data;
        cout<<"Value is :"<<val<<endl;
        delete temp;

    }
}

void peek(int pos){

    if(pos<0 || top==NULL)
    {
        cout<<"Invalid Index"<<endl;
    }else{
        for(int i=0;i<pos-1;i++){
            top=top->next;
        }
        cout<<top->data<<endl;;
    }
}


void display()
{
 struct Node *p;
 p=top;
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}

void isFull(){
    struct Node *temp;
    temp=new Node;
    if(temp==NULL){
        cout<<"Stack full"<<endl;
    }
}

void isEmpty()
{
    if(top==NULL){
        cout<<"Stack empty"<<endl;
    }
}

void stackTop(){
    struct Node *temp=top;
 if(top==NULL){
        cout<<"Stack empty"<<endl;
    }else{
        while(temp){
            temp=temp->next;
        }
        cout<<"Peek value :"<<temp->data<<endl;
    }
}

int main()
{
    push(10);
    push(12);
    push(14);
    display();
    pop();
    pop();
    stackTop();
    display();
    peek(2);
    isFull();
    isEmpty();
    stackTop();

    return 0;

}

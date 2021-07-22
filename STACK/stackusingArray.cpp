#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int size;
    int top;
    int *ptr;
};

void create(struct Node *s)
{
    cout<<"Enter the size of stack :";
    cin>>s->size;
    s->top=-1;
    s->ptr=new int[s->size];
    cout<<"Stack Created"<<endl;
}

void push(struct Node *s,int data)
{
    if(s->top==s->size-1){
        cout<<"Stack Overflow"<<endl;
    }else{
        s->top+=1;
        s->ptr[s->top]=data;
    }
}

void pop(struct Node *s)
{
    int val;

    if(s->top==-1){
        cout<<"Stack Underflow"<<endl;
    }else{
        val=s->ptr[s->top];
        s->top-=1;
        cout<<"Popped Value :"<<val<<endl;
    }
}

void display(struct Node s){
    for(int i=s.top;i>=0;i--){
        cout<<s.ptr[i]<<" ";
    }
    cout<<endl;
}

void peek(struct Node s,int pos)
{
    if(s.top-pos+1<0){
        cout<<"INAVLID INDEX"<<endl;
    }else{
        cout<<"Peek Value :"<<s.ptr[s.top-pos+1]<<endl;
    }
}

void isFull(struct Node s){
    if(s.top==s.size-1){
        cout<<"Stack FULL"<<endl;
    }
}

void isEmpty(struct Node s){
    if(s.top==-1){
        cout<<"Stack Empty"<<endl;
    }
}

void stackTop(struct Node s){
    if(s.top==-1){
        cout<<"Stack Empty"<<endl;
    }else
    {
        cout<<"Stack Top :"<<s.ptr[s.top]<<endl;
    }
}

int main(){
    struct Node s;
    create(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    pop(&s);
    peek(s,2);
    isFull(s);
    isEmpty(s);
    stackTop(s);
    display(s);
}

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int size;
    int top;
    char *ptr;
}s;


void push(char data)
{
    if(s.top==s.size-1){
        cout<<"Stack Overflow"<<endl;
    }else{
        s.top+=1;
        s.ptr[s.top]=data;
    }
}

void pop()
{
    char val;

    if(s.top==-1){
        cout<<"Stack Underflow"<<endl;
    }else{
        val=s.ptr[s.top];
        s.top-=1;
        cout<<"Popped Value :"<<val<<endl;
    }
}

void display(){
    for(int i=s.top;i>=0;i--){
        cout<<s.ptr[i]<<" ";
    }
    cout<<endl;
}

void peek(int pos)
{
    if(s.top-pos+1<0){
        cout<<"INAVLID INDEX"<<endl;
    }else{
        cout<<"Peek Value :"<<s.ptr[s.top-pos+1]<<endl;
    }
}

void isFull(){
    if(s.top==s.size-1){
        cout<<"Stack FULL"<<endl;
    }
}

void isEmpty(){
    if(s.top==-1){
        cout<<"Balanced"<<endl;
    }
}

void stackTop(){
    if(s.top==-1){
        cout<<"Stack Empty"<<endl;
    }else
    {
        cout<<"Stack Top :"<<s.ptr[s.top]<<endl;
    }
}



void isBalanced()
{
    char exp[100];
    cout<<"Enter the expression :";
    cin>>exp;
    s.top=-1;
    s.size=strlen(exp);
    s.ptr=new char[s.size];
    cout<<"Stack Created"<<endl;

    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            push(exp[i]);
        }

        if(exp[i]==')'){
            isEmpty();
            pop();
        }
    }

    isEmpty();

}


int main(){

    isBalanced();
    display();

    return 0;
}






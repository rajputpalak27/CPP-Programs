#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int size;
    int top;
    int * p;

    void push(Stack *,int);
    void pop(Stack *);
    void peek(Stack *,int);
    void stackTop(Stack *);
    void isFull(Stack *);
    void isEmpty(Stack *);
    void display(Stack *);
};

void Stack::push(Stack *s,int data){
    if(s->top==s->size-1){
        cout<<"Stack Overflow"<<endl;
    }else{
        s->top+=1;
        s->p[s->top]=data;
    }cout<<endl;
}

void Stack::pop(Stack * s){
    int temp;
    if(s->top==-1){
        cout<<"Stack Underflow"<<endl;
    }else{
        temp=s->p[s->top];
        s->top-=1;
        cout<<"Element removed: "<<temp<<endl;
    }

}

void Stack::peek(Stack *s,int pos){
    int temp;
    if(pos>size && pos<0){
        cout<<"INVALD INDEX"<<endl;
    }else{
        temp=s->p[s->top-pos+1];
        cout<<"Value at position :"<<temp<<endl;
    }
}

void Stack::stackTop(Stack * s){
    if(s->top==-1){
        cout<<"-1";
    }else{
        cout<<s->p[s->top]<<endl;
    }
}

void Stack::isFull(Stack * s){
    if(s->top==size-1){
        cout<<"Stack is Full"<<endl;
    }
}

void Stack::isEmpty(Stack * s){
    if(s->top==-1){
        cout<<"Stack is Empty"<<endl;
    }
}

void Stack::display(Stack *s){
    cout<<"------------------STACK--------------------"<<endl;
    for(int i=s->top;i>=0;i--){
        cout<<s->p[i]<<" ";
    }
     cout<<"------------------------------------------"<<endl<<endl;
}
int main(){
Stack s;
cout<<"Enter the stack size"<<endl;
cin>>s.size;
s.top=-1;
s.p=new int[s.size];

s.push(&s,10);
s.push(&s,20);
s.push(&s,30);
s.push(&s,40);
s.display(&s);
s.pop(&s);
s.display(&s);
s.peek(&s,2);
s.display(&s);
s.stackTop(&s);
s.isFull(&s);
s.isEmpty(&s);


return 0;
}

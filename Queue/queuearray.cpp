#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *que;
}q;

void create(){
    cout<<"Enter size of the queue:";
    cin>>q.size;
    q.que=new int[q.size];
    q.front=q.rear=-1;
}

void enqueue(int data){
    if(q.rear==q.size-1){
        cout<<"Queue Full can't insert"<<endl;
    }else{
        q.rear++;
        q.que[q.rear]=data;
    }
}

int dequeue(){
    int ele=-1;
    if(q.front==q.rear){
        cout<<"Queue is empty can't remove"<<endl;
    }else{
        q.front++;
        ele=q.que[q.front];
    }
    return ele;
}

int isFull(){
    if(q.rear==q.size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if(q.rear==q.front){
        return 1;
    }else{
        return 0;
    }
}

void display(){
    for(int i=q.front+1;i<=q.rear;i++){
        cout<<q.que[i]<<" ";
    }
}
int main(){

    create();
    cout<<endl<<"Queue Full : "<<isFull()<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    cout<<endl<<"Queue Empty : "<<isEmpty()<<endl;
    dequeue();

    display();

    cout<<endl<<"Queue Full : "<<isFull()<<endl;
    cout<<endl<<"Queue Empty : "<<isEmpty()<<endl;
    display();
    return 0;
}

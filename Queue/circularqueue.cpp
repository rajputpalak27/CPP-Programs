#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *que;
};

void create(struct Queue *q){
    cout<<"Enter size of the queue:";
    cin>>q->size;
    q->que=new int[q->size];
    q->front=q->rear=0;
}

void enqueue(struct Queue *q,int data){
    if((q->rear+1)%q->size==q->front){
        cout<<"Queue Full can't insert"<<endl;
    }else{
        q->rear=(q->rear+1)%q->size;
        q->que[q->rear]=data;
    }
}

int dequeue(struct Queue *q){
    int ele=-1;
    if(q->front==q->rear){
        cout<<"Queue is empty can't remove"<<endl;
    }else{
        q->front=(q->front+1)%q->size;
        ele=q->que[q->front];
    }
    return ele;
}

int isFull(struct Queue q){
    if((q.rear+1)%q.size==q.front){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Queue q){
    if(q.rear==q.front){
        return 1;
    }else{
        return 0;
    }
}

void display(struct Queue q){
    int i=q.front+1;
    cout<<"-----------------QUEUE------------"<<endl;

    do{
        cout<<q.que[i]<<" " ;
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);

    cout<<endl;
}

int main(){

    struct Queue q;
    create(&q);
    cout<<endl<<"Queue Full : "<<isFull(q)<<endl;
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(q);

    cout<<endl<<"Queue Empty : "<<isEmpty(q)<<endl;
    cout<<dequeue(&q)<<" ";
    cout<<dequeue(&q)<<" ";
    cout<<endl;
    display(q);

    cout<<endl<<"Queue Full : "<<isFull(q)<<endl;
    cout<<endl<<"Queue Empty : "<<isEmpty(q)<<endl;

    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    cout<<dequeue(&q)<<" ";
    cout<<dequeue(&q)<<" ";
    display(q);

    return 0;
}

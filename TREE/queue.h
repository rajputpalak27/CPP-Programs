#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    struct TreeNode *lchild,*rchild;
    int data;
};

struct Queue{
    int size;
    int front;
    int rear;
    TreeNode **que;
};

void create(struct Queue *q){
    cout<<"Enter size of the queue:";
    cin>>q->size;
    q->que=new TreeNode*[q->size];
    q->front=q->rear=-1;
}

void enqueue(struct Queue *q,struct TreeNode *data){
    if(q->rear==q->size-1){
        cout<<"Queue Full can't insert"<<endl;
    }else{
        q->rear++;
        q->que[q->rear]=data;
    }
}

TreeNode *dequeue(struct Queue *q){
    struct TreeNode *ele=NULL;
    if(q->front==q->rear){
        cout<<"Queue is empty can't remove"<<endl;
    }else{
        q->front++;
        ele=q->que[q->front];
    }
    return ele;
}



int isEmpty(struct Queue q){
    if(q.rear==q.front){
        return 1;
    }else{
        return 0;
    }
}

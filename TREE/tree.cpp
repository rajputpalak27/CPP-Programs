#include<bits/stdc++.h>
#include "queue.h";
using namespace std;

struct TreeNode *root=NULL;

void createTree(){
    struct TreeNode *temp,*parent;
    int ele;
    struct Queue q;
    create(&q);

    cout<<"Enter the data value for root :";
    cin>>ele;
    root=new TreeNode;
    root->data=ele;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){

        parent=dequeue(&q);

        cout<<"Enter the left child :";
        cin>>ele;
        if(ele!=-1){
            temp=new TreeNode;
            temp->data=ele;
            temp->lchild=temp->rchild=NULL;
            parent->lchild=temp;
            enqueue(&q,temp);
        }

        cout<<"Enter the right child :";
        cin>>ele;
        if(ele!=-1){
            temp=new TreeNode;
            temp->data=ele;
            temp->lchild=temp->rchild=NULL;
            parent->rchild=temp;
            enqueue(&q,temp);
        }
    }
    cout<<endl;
}

void preOrder(struct TreeNode *parent){

    if(parent){
        cout<<parent->data<<" ";
        preOrder(parent->lchild);
        preOrder(parent->rchild);
    }

}

void inOrder(struct TreeNode *parent){

    if(parent){
        inOrder(parent->lchild);
        cout<<parent->data<<" ";
        inOrder(parent->rchild);
    }
}

void postOrder(struct TreeNode *parent){
    if(parent){

        postOrder(parent->lchild);
        postOrder(parent->rchild);
        cout<<parent->data<<" ";
    }
}

void levelOrder(struct TreeNode *parent){
    struct Queue q;
    create(&q);

    cout<<parent->data<<" ";
    enqueue(&q,parent);

    while(!isEmpty(q)){
        parent=dequeue(&q);
        if(parent->lchild){
            cout<<parent->lchild->data<<" ";
            enqueue(&q,parent->lchild);
        }

         if(parent->rchild){
            cout<<parent->rchild->data<<" ";
            enqueue(&q,parent->rchild);
        }
    }

}
int main(){
    createTree();

    cout<<"PREORDER:";
    preOrder(root);
    cout<<endl;

    cout<<"INORDER:";
    inOrder(root);
    cout<<endl;

    cout<<"POSTORDER:";
    postOrder(root);
    cout<<endl;

    cout<<"LEVEL ORDER:"<<endl;
    levelOrder(root);
    cout<<endl;


    return 0;
}



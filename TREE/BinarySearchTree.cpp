#include<bits/stdc++.h>
using namespace std;

struct BinaryTree{
    struct BinaryTree *lchild,*rchild;
    int data;
};

struct BinaryTree* firstNode(int data){
    struct BinaryTree *temp=new BinaryTree;
    temp->data=data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

struct BinaryTree *search(struct BinaryTree *parent,int key){
    if(parent==NULL){
        cout<<" NODE NOT PRESENT";
        return parent;
    }else if( parent->data==key){
        return parent;
    }else if(key<parent->data){
        return search(parent->lchild,key);
    }else{
        return search(parent->rchild,key);
    }
};

void inOrder(struct BinaryTree *parent){
    if(parent!=NULL){
        inOrder(parent->lchild);
        cout<<parent->data<<" ";
        inOrder(parent->rchild);
    }
}

struct BinaryTree* insert(struct BinaryTree *parent,int key){

    if(parent==NULL){
        return firstNode(key);
    }

    if(key < parent->data){
        parent->lchild=insert(parent->lchild,key);
    }else{
        parent->rchild=insert(parent->rchild,key);
    }

    return parent;

}

struct BinaryTree * rightPredecessor(struct BinaryTree *parent)
{
        struct BinaryTree *temp=parent;

        while(temp && temp->lchild !=NULL){
            temp=temp->lchild;
        }

        return temp;
};


struct BinaryTree* del(struct BinaryTree *parent,int key)
{
    if(parent==NULL){
        return parent;
    }else if(key<parent->data){
        parent->lchild=del(parent->lchild,key);
    }else if(key>parent->data){
        parent->rchild=del(parent->rchild,key);
    }else{
        if(parent->lchild==NULL){
            struct BinaryTree *curr;
            curr=parent->rchild;
            delete parent;
            return curr;
        }

        if(parent->rchild==NULL){
            struct BinaryTree *curr;
            curr=parent->lchild;
            delete parent;
            return curr;
        }

        struct BinaryTree *dnode=rightPredecessor(parent->rchild);
        parent->data=dnode->data;

        parent->rchild=del(parent->rchild,key);
    }

        return parent;

};


int main(){

struct BinaryTree *root=NULL,*s;
root=insert(root,50);
insert(root,10);
insert(root,40);
insert(root,20);
insert(root,30);

cout<<"TREE TRAVERSAL:";
inOrder(root);
cout<<endl;

root=del(root,50);
cout<<"TREE TRAVERSAL:";
inOrder(root);
cout<<endl;

root=del(root,200);
cout<<"TREE TRAVERSAL:";
inOrder(root);
cout<<endl;

s=search(root,200);
cout<<s->data<<" - PRESENT AT:"<<s;
return 0;
}

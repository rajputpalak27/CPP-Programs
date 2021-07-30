#include<bits/stdc++.h>
using namespace std;

struct AVL
{
    struct AVL *lchild,*rchild;
    int data,height;
};

int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int getHeight(struct AVL *parent){
    if(parent==NULL){
        return 0;
    }else{
        return parent->height;
    }
}

int balanceFactor(struct AVL *parent)
{
    if(parent==NULL){
        return 0;
    }else{
        return getHeight(parent->lchild)-getHeight(parent->rchild);
    }
}

struct AVL *rightRotate(struct AVL *parent)
{
    struct AVL *pl=parent->lchild;
    struct AVL *plr=pl->rchild;

    pl->rchild=parent;
    parent->lchild=plr;

    parent->height=1+max(getHeight(parent->lchild),getHeight(parent->rchild));
    pl->height-1+max(getHeight(pl->lchild),getHeight(pl->rchild));



    return pl;
};


struct AVL *leftRotate(struct AVL *parent){
    struct AVL *pr=parent->rchild;
    struct AVL *prl=pr->lchild;

    pr->lchild=parent;
    parent->rchild=prl;

    parent->height=1+max(getHeight(parent->lchild),getHeight(parent->rchild));
    pr->height=1+max(getHeight(pr->lchild),getHeight(pr->rchild));


    return pr;
};


struct AVL * firstNode(struct AVL *parent,int key){
    struct AVL *temp=new AVL;
    temp->data=key;
    temp->lchild=temp->rchild=NULL;
    temp->height=1;

    return temp;
};

struct AVL * insert(struct AVL *parent,int key)
{
    if(parent==NULL){
        return firstNode(parent,key);
    }else if(key<parent->data){
        parent->lchild=insert(parent->lchild,key);
    }else if(key>parent->data){
        parent->rchild=insert(parent->rchild,key);
    }else{
        return parent;
    }

    parent->height=1+max(getHeight(parent->lchild),getHeight(parent->rchild));

    int balance;
    balance=balanceFactor(parent);

    //LL
    if(balance>1 && key<parent->lchild->data){
        return rightRotate(parent);
    }

    //LR
    if(balance>1 && key>parent->lchild->data){
        parent->lchild=leftRotate(parent->lchild);
        return rightRotate(parent);
    }

    //RR
    if(balance>-1 && key>parent->lchild->data){
        return leftRotate(parent);
    }

    //RL
    if(balance>-1 && key<parent->lchild->data){
        parent->rchild=rightRotate(parent->rchild);
        return leftRotate(parent);
    }

    return parent;
};

struct AVL * rightPredecessor(struct AVL *parent)
{
        struct AVL *temp=parent;

        while(temp && temp->lchild !=NULL){
            temp=temp->lchild;
        }

        return temp;
};

struct AVL *del(struct AVL *parent,int key){

    if(parent==NULL){
        return parent;
    }else if(key<parent->data){
        parent->lchild=del(parent->lchild,key);
    }else if(key>parent->data){
        parent->rchild=del(parent->rchild,key);
    }else{
        if((parent->lchild==NULL)||(parent->rchild==NULL)){
            struct AVL *temp=parent->lchild ? parent->lchild:parent->rchild;

            if(temp==NULL){
                temp=parent;
                parent=NULL;
            }else{
                *parent=*temp;
            }
            delete parent;

        }else{

        struct AVL *dnode=rightPredecessor(parent->rchild);

        parent->data=dnode->data;

        parent->rchild=del(parent->rchild,key);

        }
    }

    if(parent==NULL){
        return parent;
    }

     parent->height=1+max(getHeight(parent->lchild),getHeight(parent->rchild));

    int balance;
    balance=balanceFactor(parent);

    if(balance>1 && balanceFactor(parent->lchild)>=0){
        return rightRotate(parent);
    }else if(balance>1 && balanceFactor(parent->lchild)<0){
        parent->rchild=leftRotate(parent->lchild);
        return rightRotate(parent);
    }else if(balance<-1 && balanceFactor(parent->rchild)<=0){
        return leftRotate(parent);
    }else if(balance<-1 && balanceFactor(parent->rchild)>0){
        parent->rchild=rightRotate(parent->rchild);
        return leftRotate(parent);
    }
        return parent;

};


void inOrder(struct AVL *parent){
    if(parent!=NULL){
        cout<<parent->data<<" ";
        inOrder(parent->lchild);
        inOrder(parent->rchild);
    }
}



int main()
{
    struct AVL *root=NULL;

    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 22);

    cout<<"TREE TRAVERSAL:";
    inOrder(root);
    cout<<endl;


    root = del(root, 10);

    cout<<"TREE TRAVERSAL:";
    inOrder(root);
    cout<<endl;
    return 0;
}

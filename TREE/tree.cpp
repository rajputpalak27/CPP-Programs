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

        cout<<"Enter the left child of "<<parent->data<<" : ";
        cin>>ele;
        if(ele!=-1){
            temp=new TreeNode;
            temp->data=ele;
            temp->lchild=temp->rchild=NULL;
            parent->lchild=temp;
            enqueue(&q,temp);
        }

        cout<<"Enter the right child of "<<parent->data<<" : ";
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

int countAllNode(struct TreeNode *parent){
    int x,y;
    x=y=0;
    if(parent!=NULL){
        x=countAllNode(parent->lchild);
        y=countAllNode(parent->rchild);
        return x+y+1;
    }
}

int countInternalNode(struct TreeNode *parent)
{
    if(parent==NULL){
        return 0;
    }

    if(parent->lchild || parent->rchild){
        return countInternalNode(parent->lchild)+countInternalNode(parent->rchild)+1;
    }
}

int count2DegreeNode(struct TreeNode *parent)
{
      if(parent==NULL){
        return 0;
    }

    if(parent->lchild && parent->rchild){
        return count2DegreeNode(parent->lchild)+count2DegreeNode(parent->rchild)+1;
    }
}

int count1DegreeNode(struct TreeNode *parent)
{
      if(parent==NULL){
        return 0;
    }

    if((parent->lchild && !parent->rchild) || (!parent->lchild && parent->rchild)){
        return count1DegreeNode(parent->lchild)+count1DegreeNode(parent->rchild)+1;
    }else{
        return count1DegreeNode(parent->lchild)+count1DegreeNode(parent->rchild);
    }
}

int countLeafNode(struct TreeNode *parent)
{
    if(parent==NULL){
        return 0;
    }

    if(!parent->lchild && !parent->rchild){
        return countLeafNode(parent->lchild)+countLeafNode(parent->rchild)+1;
    }else{
        return countLeafNode(parent->lchild)+countLeafNode(parent->rchild);
    }
}


int height(struct TreeNode *parent){
    int x,y;
    x=y=0;
    if(parent ==0){
        return 0;
    }else{
        x=height(parent->lchild);
        y=height(parent->rchild);

        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
}

int nodeSum(struct TreeNode *parent){
    int x,y;
    x=y=0;

    if(parent!=NULL){
        x=nodeSum(parent->lchild);
        y=nodeSum(parent->rchild);
        return x+y+parent->data;
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

    cout<<"TOTAL NODES IN TREE:"<<endl;
    cout<<countAllNode(root);
    cout<<endl;

    cout<<"INTERNAL NODES IN TREE:"<<endl;
    cout<<countInternalNode(root);
    cout<<endl;

    cout<<"2 DEGREE NODES IN TREE:"<<endl;
    cout<<count2DegreeNode(root);
    cout<<endl;

    cout<<"1 DEGREE NODES IN TREE:"<<endl;
    cout<<count1DegreeNode(root);
    cout<<endl;

    cout<<"LEAF NODES IN TREE:"<<endl;
    cout<<countLeafNode(root);
    cout<<endl;

    cout<<"HEIGHT OF TREE:"<<endl;
    cout<<height(root);
    cout<<endl;

    cout<<"Sum of Elements of TREE:"<<endl;
    cout<<nodeSum(root);
    cout<<endl;


    return 0;
}



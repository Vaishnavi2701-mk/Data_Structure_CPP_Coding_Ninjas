#include <iostream>
#include<queue>
using namespace std;
#include "binarytreeRecurssiveClass.h"
//1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> printNodes;
printNodes.push(root);
while(printNodes.size()!=0){
    BinaryTreeNode<int>*front=printNodes.front();
    printNodes.pop();
    cout<<front->data<<":";
    if(front->left!=NULL){
        cout<<"L:"<<front->left->data<<",";
        printNodes.push(front->left);
    }
    else{
        cout<<"L:"<<-1<<",";
    }

      if(front->right!=NULL){
        cout<<"R:"<<front->right->data;
        printNodes.push(front->right);
    }
    else{
            cout<<"R:"<<-1;
    }
    cout<<endl;
}
}

BinaryTreeNode<int>* takeInputLevelWise(){
int rootData;
cout<<"Enter the root data: "<<endl;
cin>>rootData;

if(rootData==-1){
    return NULL;
}

BinaryTreeNode <int> * root=new BinaryTreeNode<int>(rootData);
queue<BinaryTreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(pendingNodes.size()!=0){
    BinaryTreeNode<int>*front=pendingNodes.front();
    pendingNodes.pop();

    cout<<"Enter the left child of "<<front->data<<endl;
    int leftChild;
    cin>>leftChild;
    if(leftChild!=-1){
    BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChild);
    front->left=child;
    pendingNodes.push(child);
    }


    cout<<"Enter the right child of "<<front->data<<endl;
    int rightChild;
    cin>>rightChild;
    if(rightChild!=-1){
    BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChild);
    front->right=child;
    pendingNodes.push(child);
    }




}

return root;

}

void nodesWithoutSiblings(BinaryTreeNode<int>*root){
if(root==NULL)
    return;

if(root->left!=NULL&&root->right!=NULL){
    nodesWithoutSiblings(root->left);
    nodesWithoutSiblings(root->right);
}

else if(root->right){
    cout<<root->right->data<<endl;
    nodesWithoutSiblings(root->right);
}

else if(root->left){

    cout<<root->left->data<<endl;
nodesWithoutSiblings(root->left);

}


}

int main(){
BinaryTreeNode<int>*root=takeInputLevelWise();
printLevelWise(root);
cout<<endl<<"Nodes not having any siblings: "<<endl;
nodesWithoutSiblings(root);


}


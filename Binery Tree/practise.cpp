#include <iostream>
#include <queue>
#include "binarytreeRecurssiveClass.h"
using namespace std;
// 1 2 3 4 5 -1 -1 -1 -1 -1 -1

//takeInputLevelWise
BinaryTreeNode<int>*takeInputlevelWise(){
int rootData;
cout<<"Enter the root data:"<<endl;
cin>>rootData;
if(rootData==-1){
    return NULL;
}
BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);

queue<BinaryTreeNode<int>*> pendingNodes;

pendingNodes.push(root);

while(!pendingNodes.empty()){
    BinaryTreeNode<int>*front=pendingNodes.front();
    pendingNodes.pop();
    int leftchild;
    cout<<"Enter the left child of : "<<front->data<<endl;
    cin>>leftchild;
    if(leftchild!=-1){
        BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftchild);
        front->left=child;
        pendingNodes.push(child);
    }
      int rightchild;
    cout<<"Enter the right child of : "<<front->data<<endl;
    cin>>rightchild;
    if(rightchild!=-1){
        BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightchild);
        front->right=child;
        pendingNodes.push(child);
    }
}

return root;

}

//printInputLevelWise
void printLevelWise(BinaryTreeNode<int>*root){
if(root==NULL){
    return;
}
queue <BinaryTreeNode<int>*> printNodes;
printNodes.push(root);
while(printNodes.size()!=0){
    BinaryTreeNode<int>*front=printNodes.front();
    printNodes.pop();
    cout<<front->data<<":"<<" ";
    if(front->left!=NULL){
        cout<<"L"<<" "<<":"<<front->left->data<<",";
        printNodes.push(front->left);
    }
    else{
        cout<<"L"<<" "<<":"<<-1<<",";
    }
     if(front->right!=NULL){
        cout<<"R"<<" "<<":"<<front->right->data<<endl;
        printNodes.push(front->right);
    }
    else{
        cout<<"R"<<" "<<":"<<-1<<endl;
    }
}
}

//CountNodes
int countNodes(BinaryTreeNode<int>*root){
//base case
if(root==NULL){
    return 0;
}
return 1+countNodes(root->left)+countNodes(root->right);
}

//findNode present/Absent

bool isnodePresent(BinaryTreeNode<int>*root,int x){
if(root==NULL){
    return false;
}
if(root->data==x){
    return true;
}
if(isnodePresent(root->left,x)){
    return true;
}
else if(isnodePresent(root->right,x)){
    return true;
}
return false;

}

//height of tree

int height(BinaryTreeNode<int>*root){
if(root==NULL){
    return 0;
}
int heightOfTree=max(height(root->left),height(root->right));
return 1+heightOfTree;

}

//Mirror Image

void mirrorImage(BinaryTreeNode<int>*root){
if(root==NULL){
    return;
}
BinaryTreeNode<int>*temp;
if(root->left!=NULL&&root->right!=NULL){
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}
mirrorImage(root->left);
mirrorImage(root->right);
}

//In-order Traversal

void inorderPrint(BinaryTreeNode<int>*root){
if(root==NULL){
    return;
}
inorderPrint(root->left);
cout<<root->data<<" ,";
inorderPrint(root->right);


}

//pre-order printing
void preOrder(BinaryTreeNode<int>*root){

if(root==NULL){
    return;
}
cout<<root->data<<",";
preOrder(root->left);
preOrder(root->right);
}

//post-Order printing

void postOrder(BinaryTreeNode<int>*root){
if(root==NULL){
    return;
}
postOrder(root->left);
postOrder(root->right);
cout<<root->data<<",";

}

/* bad time complexity

diameter of tree(maximum distance between two nodes)
int diameter(BinaryTreeNode<int>*root){
if(root==NULL){
    return 0;
}
int option1=height(root->left)+height(root->right);
int option2=diameter(root->left);
int option3=diameter(root->right);

return max(option1,max(option2,option3));
}*/

// using inbuilt pair function to calculate height and diameter at once:
pair<int,int> heightDiameter(BinaryTreeNode<int>*root){

if(root==NULL){
    pair<int,int> p;
    p.first=0;
    p.second=0;
    return p;
}

pair<int,int> leftChild=heightDiameter(root->left);
pair<int,int> rightChild=heightDiameter(root->right);

int lh=leftChild.first;
int ld=leftChild.second;
int rh=rightChild.first;
int rd=rightChild.second;

int height=1+max(lh,rh);
int diameter=max(lh+rh,max(ld,rd));

pair<int,int> p;
p.first=height;
p.second=diameter;
return p;

}

int main()
{
cout<<"Take Input LevelWise: "<<endl;
BinaryTreeNode<int>*root=takeInputlevelWise();
cout<<"Print Tree LevelWise:"<<endl;
printLevelWise(root);
cout<<"Number of Nodes are: "<<countNodes(root)<<endl;
int x;
cin>>x;
cout<<"Node is present/Absent: "<<isnodePresent(root,x)<<endl;
cout<<"Height of Tree: "<<height(root)<<endl;
cout<<"Mirror Image of Tree: "<<endl;
mirrorImage(root);
printLevelWise(root);
cout<<endl;
//again in original format:
cout<<"Original Format: "<<endl;
mirrorImage(root);
printLevelWise(root);
cout<<endl;
cout<<"In-order Traversal: "<<endl;
inorderPrint(root);
cout<<endl;
cout<<"pre-order Traversal: "<<endl;
preOrder(root);
cout<<endl;
cout<<"Post-Order Traversal: "<<endl;
postOrder(root);
cout<<endl;
cout<<"Height and Diameter: "<<endl;
//imp
pair<int,int> p=heightDiameter(root);
cout<<"Height: "<<p.first<<endl;
cout<<"Diameter: "<<p.second<<endl;


}

#include <iostream>
#include<queue>
using namespace std;
#include "binarytreeRecurssiveClass.h"

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
/* worst time complexity
int height(BinaryTreeNode<int>*root){
if(root==NULL){
   return 0;
}
return 1+max(height(root->left),height(root->right));

}

int diameterOfTree(BinaryTreeNode<int>*root){
if(root==NULL){
    return 0;
}
int option1=height(root->left)+height(root->right);
int option2=diameterOfTree(root->left);
int option3=diameterOfTree(root->right);

return max(option1,max(option2,option3));
}
*/

// pair is built-in function and template and it have first and second;

pair<int,int> heightDiameter(BinaryTreeNode<int>*root){
if(root==NULL){
    pair<int,int> p;
    p.first=0;
    p.second=0;
    return p;
}

pair<int,int> leftChild=heightDiameter(root->left);
pair<int,int> rightChild=heightDiameter(root->right);

int ld=leftChild.second;
int lh=leftChild.first;
int rd=rightChild.second;
int rh=rightChild.first;

int height=1+max(lh,rh);
int diameter=max(lh+rh,max(ld,rd));

pair<int,int> p;
p.first=height;
p.second=diameter;
return p;

}
int main(){
BinaryTreeNode<int>*root=takeInputLevelWise();
printLevelWise(root);
pair<int,int> p=heightDiameter(root);
cout<<"Height of the root:"<<p.first<<endl;
cout<<"Diameter of the root: "<<p.second<<endl;


}


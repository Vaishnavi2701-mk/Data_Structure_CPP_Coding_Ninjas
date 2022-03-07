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
// minimum and maximum in binary tree

pair<int,int> getMinAndMax(BinaryTreeNode<int>*root){

if(root->left==NULL&&root->right==NULL){
    pair<int,int>ans;
    ans.first=ans.second=root->data;
    return ans;
}

pair<int,int>ans;
ans.first=ans.second=root->data;

if(root->left!=NULL){
    pair<int,int> leftAns=getMinAndMax(root->left);
    ans.first=min(ans.first,leftAns.first);
    ans.second=max(ans.second,leftAns.second);
}
if(root->right!=NULL){
    pair<int,int>rightAns=getMinAndMax(root->right);
    ans.first=min(ans.first,rightAns.first);
    ans.second=max(ans.second,rightAns.second);
}

return ans;
}

int main(){
BinaryTreeNode<int>*root=takeInputLevelWise();
printLevelWise(root);
cout<<endl<<"Minimum and Maximum of Binary Tree: "<<endl;
pair<int,int> ans=getMinAndMax(root);
cout<<"Minimum: "<<ans.first<<endl;
cout<<"Maximum: "<<ans.second<<endl;

}


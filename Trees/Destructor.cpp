#include<iostream>
#include<queue>
#include "Tree.h"
using namespace std;

TreeNode<int> * takeInputLevelWise(){

int rootData;
cout<<"Enter the root Data"<<endl;
cin>>rootData;
TreeNode <int> * root=new TreeNode<int>(rootData);
queue <TreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(pendingNodes.size()!=0){
    TreeNode<int> * front=pendingNodes.front();
    pendingNodes.pop();
  int numChild;
  cout<<"Enter the No. of child for "<<front->data<<endl;
  cin>>numChild;
  for(int i=0;i<numChild;i++){
    int childData;
    cout<<"Enter the "<<i<<" th child for "<<front->data<<endl;
    cin>>childData;
    TreeNode<int>*child=new TreeNode<int>(childData);
    front->children.push_back(child);
    pendingNodes.push(child);
  }
}

return root;
}

void postOrderPrinting(TreeNode<int>*root){
  if(root==NULL){
    return;
  }
  for(int i=0;i<root->children.size();i++){
    postOrderPrinting(root->children[i]);
  }
  cout<<root->data<<" ";
}

// function to delete tree manually like postOrderPrinting
void deleteTree(TreeNode<int>*root){
for(int i=0;i<root->children.size();i++){
    deleteTree(root->children[i]);
}
delete root;
}

int main(){

TreeNode<int> *root=takeInputLevelWise();
cout<<endl;
cout<<"PostOrderPrinting: "<<endl;
postOrderPrinting(root);

//we have to manually delete tree by deleteTree function;
deleteTree(root);
}

/* but instead of that if we made destructor then it automatically delete by calling root;

like;

~TreeNode(){
for(int i=0;i<children.size();i++){
    delete children[i];
}
}

until all children deleted destructor will not going to end; at last root will delete;*/

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
    cin>>childData;                                                   // we only take the data for child but did not make the node for it;
    TreeNode<int>*child=new TreeNode<int>(childData);                 // create a node for child
    front->children.push_back(child);                                 // join that child with root
    pendingNodes.push(child);                                         // push that child in the queue
  }
}

return root;
}

void preOrderPrinting(TreeNode<int>*root){
if(root==NULL){
    return;
}
cout<<root->data<<" ";
for(int i=0;i<root->children.size();i++){
    preOrderPrinting(root->children[i]);
}

}

int main(){

TreeNode<int> *root=takeInputLevelWise();

cout<<"PreOrderPrinting: "<<endl;
preOrderPrinting(root);

}

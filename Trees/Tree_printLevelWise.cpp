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

void printLevelWise(TreeNode<int>*root){
queue<TreeNode<int>*> printNode;
printNode.push(root);
while(!printNode.empty()){
   TreeNode<int>*front=printNode.front();
   printNode.pop();
   cout<<front->data<<":";
   for(int i=0;i<front->children.size();i++){
    if(i==front->children.size()-1){
        cout<<front->children[i]->data;
        printNode.push(front->children[i]);
    }
    else{
        cout<<front->children[i]->data<<",";
        printNode.push(front->children[i]);
    }
   }
   cout<<endl;
}

}

int main(){

TreeNode<int> *root=takeInputLevelWise();
printLevelWise(root);

}

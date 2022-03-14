/*
Code : PostOrder Traversal

Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10
*/

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

int main(){

TreeNode<int> *root=takeInputLevelWise();
cout<<endl;
cout<<"PostOrderPrinting: "<<endl;
postOrderPrinting(root);

}

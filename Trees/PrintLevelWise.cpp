/*
Print Level Wise

Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements of the tree in level wise order, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:*/

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

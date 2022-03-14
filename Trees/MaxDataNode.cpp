
/*
Code : Max data node

Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the data of the node with largest data in the given tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
*/

#include<iostream>
#include<queue>
using namespace std;
#include "Tree.h"

TreeNode<int> * takeInputLevelWise(){

int rootData;
cout<<"Enter the rootData: "<<endl;
cin>>rootData;

TreeNode<int>* root=new TreeNode<int>(rootData);

queue <TreeNode<int>*> pendingNodes;       // it contain all the children of parents;

pendingNodes.push(root);
while(!pendingNodes.empty()){
    TreeNode <int>*front= pendingNodes.front();
    pendingNodes.pop();

    cout<<"Enter the number of children of "<<front->data<<endl;
    int numChild;
    cin>>numChild;

    for(int i=0;i<numChild;i++){
        cout<<"Enter the "<<i<<" th child of"<<front->data<<endl;
        int childData;
        cin>>childData;
        TreeNode<int>*child=new TreeNode<int>(childData);
        front->children.push_back(child);
        pendingNodes.push(child);


    }


}
return root;

}
TreeNode<int> *maxDataNodeHelper(TreeNode<int>*root,TreeNode<int>*ans){
//edge case
if(root==NULL){
    return NULL;
}
for(int i=0;i<root->children.size();i++){
    if(root->children[i]->data>ans->data){
        ans=root->children[i];
        ans=maxDataNodeHelper(root->children[i],ans);
    }
}
return ans;

}

TreeNode<int> *maxDataNode(TreeNode<int>*root){
maxDataNodeHelper(root,root);
}

int main(){
TreeNode<int>*root=takeInputLevelWise();
cout<<endl;
TreeNode<int>* ans = maxDataNode(root);
cout<<ans->data<<endl;
}

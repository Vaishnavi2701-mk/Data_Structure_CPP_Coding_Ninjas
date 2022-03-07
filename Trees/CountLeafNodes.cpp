

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
int getCountOfLeafNodes(TreeNode<int>*root){
//edge case
if(root==NULL){
    return NULL;
}
//base case;
if(root->children.size()==0){
    return 1;
}
int count=0;
for(int i=0;i<root->children.size();i++){
    count+=getCountOfLeafNodes(root->children[i]);
}
return count;
}

int main(){
TreeNode<int>*root=takeInputLevelWise();
cout<<endl;
cout<<getCountOfLeafNodes(root)<<endl;
}

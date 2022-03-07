#include<iostream>
using namespace std;
#include "Tree.h"


/*  it is ok but it is not relevant as it is not properly showing that who is the child of whome
void printTree(TreeNode<int>*root){
cout<<root->data<<endl;
for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
}
}*/

void printTree(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
cout<<root->data<<":";
for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<",";
}
cout<<endl;
for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
}
}

TreeNode <int> * takeInput(){

int rootData;
cout<<"Enter the data"<<endl;
cin>>rootData;

TreeNode <int> * root=new TreeNode<int>(rootData);

int n;
cout<<"Enter the no.of children of: "<<rootData<<endl;
cin>>n;

for(int i=0;i<n;i++){
    TreeNode<int>* child=takeInput();
    root->children.push_back(child);
}

return root;
}

int main(){

/*TreeNode <int> * root=new TreeNode<int>(1);
TreeNode <int> * node1=new TreeNode<int>(2);
TreeNode <int> * node2=new TreeNode<int>(3);

root->children.push_back(node1);
root->children.push_back(node2);*/


TreeNode<int> *root=takeInput();


printTree(root);


}

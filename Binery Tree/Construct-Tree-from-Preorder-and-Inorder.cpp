/*
Code: Construct Tree from Preorder and Inorder

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
*/
#include <iostream>
#include<queue>
using namespace std;
#include "binarytreeRecurssiveClass.h"
/*7
1 2 4 5 3 6 7
4 2 5 1 6 3 7*/
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

void levelOrderTraversal(BinaryTreeNode<int>*root){

queue<BinaryTreeNode<int>*> q;

q.push(root);
q.push(NULL);

while(!q.empty()){
BinaryTreeNode<int>*front=q.front();
q.pop();

if(front==NULL){
    if(q.empty()){
        break;
    }
    cout<<endl;
    q.push(NULL);
    continue;
}

cout<<front->data<< " ";

if(front->left){
    q.push(front->left);
}

if(front->right){
    q.push(front->right);
}



}

}
BinaryTreeNode<int>*buildTreeHelper(int in[],int pre[],int inS,int inE,int preS,int preE){
if(inS>inE)
    return NULL;

int rootData=pre[preS];
int rootIndex=-1;
 for(int i=inS;i<inE;i++){
    if(rootData==in[i]){
        rootIndex=i;
        break;
    }
 }
int leftInS=inS;
int leftInE=rootIndex-1;
int leftPreS=preS+1;
int leftPreE=leftInE-leftInS+leftPreS;
int rightInS=rootIndex+1;
int rightInE=inE;
int rightPreS=leftPreE+1;
int rightPreE=preE;

BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
root->left=buildTreeHelper(in,pre,leftInS,leftInE,leftPreS,leftPreE);
root->right=buildTreeHelper(in,pre,rightInS,rightInE,rightPreS,rightPreE);

return root;

}

BinaryTreeNode<int>* buildTree(int pre[],int preLength,int in[],int inLength){
return buildTreeHelper(in,pre,0,inLength-1,0,preLength-1);
}

int main(){

    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    cout<<"pre-order Input: "<<endl;
    for (int i = 0; i < size; i++) cin >> pre[i];
    cout<<"post-order Input: "<<endl;
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelWise(root);
}

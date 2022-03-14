/*
ZigZag tree
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/#include <iostream>
#include<queue>
#include<stack>
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

void zigZagOrder(BinaryTreeNode<int> *root) {

  if(!root)
     return;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    s1.push(root);

    while(!s1.empty() && !s1.empty())
    {
        while(!s1.empty())
        { BinaryTreeNode<int> * top=s1.top();
        s1.pop();
        cout<<top->data<<" ";

        if(top->left)
            s2.push(top->left);
       if(top->right)
            s2.push(top->right);
        }

        cout<<endl;

        while(!s2.empty())
        {
            BinaryTreeNode<int> * top=s2.top();
        s2.pop();
        cout<<top->data<<" ";

        if(top->right)
            s1.push(top->right);
        if(top->left)
            s1.push(top->left);

        }
        cout<<endl;

    }
}

int main(){
BinaryTreeNode<int>*root=takeInputLevelWise();
cout<<endl<<"Zigzag Traversal: "<<endl;
zigZagOrder(root);


}


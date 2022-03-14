/*
Print nodes at distance k from node

You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2
alt txt
Starting from the target node 5, the nodes at distance K are 7 4 and 1.
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
Output Format:
All the node data at distance K from the target node will be printed on a new line.

The order in which the data is printed doesn't matter.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5

*/
#include <iostream>
#include<vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
void   printNodesAtDistanceKDown(BinaryTreeNode<int>*root,int k){
if(root==NULL||k<0){
    return;
}
if(k==0){
    cout<<root->data<<endl;
    return;
}
printNodesAtDistanceKDown(root->left,k-1);
printNodesAtDistanceKDown(root->right,k-1);
}
int printNodesAtDistanceK(BinaryTreeNode<int>*root,int target,int k){
if(root==NULL){
    return -1;
}
if(root->data==target){
    printNodesAtDistanceKDown(root,k);
    return 0;
}
int leftOutput=printNodesAtDistanceK(root->left,target,k);
if(leftOutput!=-1){
    if(leftOutput+1==k){
        cout<<root->data<<endl;
    }
    else{
     printNodesAtDistanceKDown(root->right,k-leftOutput-2);
    }
    return 1+leftOutput;
}
int rightOutput=printNodesAtDistanceK(root->right,target,k);
if(rightOutput!=-1){
    if(rightOutput+1==k){
        cout<<root->data<<endl;
    }
    else{
     printNodesAtDistanceKDown(root->left,k-rightOutput-2);
    }
    return 1+rightOutput;
}
return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int>*root,int node,int k){
int x=printNodesAtDistanceK(root,node,k);
return;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int target,k;
    cout<<"Enter target node and k: "<<endl;
    cin>>target>>k;
    nodesAtDistanceK(root,target,k);
    delete root;
}


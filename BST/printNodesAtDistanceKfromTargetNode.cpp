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


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

int getLCA(BinaryTreeNode<int>*root,int a,int b){

if(root==NULL){
    return -1;
}
if(root->data==a||root->data==b){
    return root->data;
}
int leftOutput=getLCA(root->left,a,b);
int rightOutput=getLCA(root->right,a,b);

if(leftOutput==-1&&rightOutput==-1){
    return -1;
}
else if(leftOutput!=-1&&rightOutput==-1){
    return leftOutput;
}
else if(leftOutput==-1&&rightOutput!=-1){
    return rightOutput;
}
else{
    return root->data;
}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a,b;
    cout<<"Enter a and b: "<<endl;
    cin>>a>>b;
    cout<<getLCA(root,a,b);
    delete root;
}

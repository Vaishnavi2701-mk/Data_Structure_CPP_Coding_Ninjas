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
void rootToLeafPathSumToKHelper(BinaryTreeNode<int>*root,int k,vector<int>&v){
if(root==NULL){
    return;
}
v.push_back(root->data);
k=k-root->data;
if(root->left==NULL&&root->right==NULL){
    if(k==0){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    v.pop_back();
    return;
}
rootToLeafPathSumToKHelper(root->left,k,v);
rootToLeafPathSumToKHelper(root->right,k,v);

}
void rootToLeafPathSumToK(BinaryTreeNode<int>*root,int k){
vector<int> v;
rootToLeafPathSumToKHelper(root,k,v);
return;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cout<<"Enter sum to k: "<<endl;
    cin>>k;
    rootToLeafPathSumToK(root,k);
    delete root;
}


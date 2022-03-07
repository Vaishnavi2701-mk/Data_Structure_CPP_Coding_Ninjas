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

void convert(BinaryTreeNode<int>*root,vector<int>&v){
if(root==NULL){
    return;
}
v.push_back(root->data);
convert(root->left,v);
convert(root->right,v);
}
void PairSum(BinaryTreeNode<int>*root,int sum){
vector<int>v;
convert(root,v);
sort(v.begin(),v.end());

int i=0,j=v.size()-1;
while(i<j){
    if(v[i]+v[j]==sum){
    cout<<v[i]<<" "<<v[j]<<endl;
        i++;
        j--;
    }
    else if(v[i]+v[j]>sum){
        j--;
    }
    else{
    i++;
    }
}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cout<<"Enter target sum:" <<endl;
    cin>>sum;
    PairSum(root,sum);
    delete root;
}

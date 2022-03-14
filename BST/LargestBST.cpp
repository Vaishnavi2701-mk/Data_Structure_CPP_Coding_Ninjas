/* Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/
#include <iostream>
#include <queue>
#include<climits>
#include<cmath>
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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


class Pair{
public:
    int min;
    int max;
    bool isBST;
    int height;
    };

    Pair BST(BinaryTreeNode<int>*root){
      if(root==NULL){
        Pair p;
        p.min=INT_MAX;
        p.max=INT_MIN;
        p.isBST=true;
        p.height=0;
        return p;
      }

      Pair leftOutput=BST(root->left);
      Pair rightOutput=BST(root->right);

      int minimum=min(root->data,min(leftOutput.min,rightOutput.min));
      int maximum=max(root->data,max(leftOutput.max,rightOutput.max));
      bool isBSTFinal=(root->data>leftOutput.max)&&(root->data<rightOutput.min)&&leftOutput.isBST&&rightOutput.isBST;

      Pair p;
      p.min=minimum;
      p.max=maximum;
      p.isBST=isBSTFinal;
      if(isBSTFinal){
        p.height=1+max(leftOutput.height,rightOutput.height);
      }
      else{
        p.height=max(leftOutput.height,rightOutput.height);
      }
      return p;
    }
    int largestBSTSubtree(BinaryTreeNode<int>*root){
      return BST(root).height;
    }

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << "Largest BST Subtree Height: "<<largestBSTSubtree(root);
    delete root;
}

#include <iostream>
#include <queue>


/*7
4 5 2 6 7 3 1
4 2 5 1 6 3 7 */
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
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
BinaryTreeNode<int>*buildTreeHelper(int*post,int*in,int inS,int inE,int postS,int postE){
if(postS>postE)
    return NULL;
BinaryTreeNode<int>*root=new BinaryTreeNode<int>(post[postE]);

int k=0;
for(int i=inS;i<=inE;i++){
    if(post[postE]==in[i]){
        k=i;
        break;
    }
}

int lInS=inS;
int lInE=k-1;
int lPostS=postS;
int lPostE=lInE-lInS+lPostS;

int rInS=k+1;
int rInE=inE;
int rPostS=lPostE+1;
int rPostE=postE-1;

root->left=buildTreeHelper(post,in,lInS,lInE,lPostS,lPostE);
root->right=buildTreeHelper(post,in,rInS,rInE,rPostS,rPostE);

return root;

}
BinaryTreeNode<int>*buildTree(int* post,int postLength,int *in,int inLength){
return buildTreeHelper(post,in,0,inLength-1,0,postLength-1);
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}

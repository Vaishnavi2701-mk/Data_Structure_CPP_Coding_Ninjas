/*
Code: BST to Sorted LL

Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/

class Pair{
    public:
    
    Node<int>*head=NULL;
    Node <int> *tail=NULL;
      
};

Pair binaryToLL(BinaryTreeNode<int>*root){
    if(root==NULL){
        Pair p;
        p.head=NULL;
        p.tail=NULL;
        return p;
    }
    
    Node<int> *ansNode=new Node<int>(root->data);
    
    Pair leftChild=binaryToLL(root->left);
    Pair rightChild=binaryToLL(root->right);
    
    Pair ans;
    
    if(leftChild.head==NULL&&rightChild.head==NULL){
        ans.head=ansNode;
        ans.tail=ansNode;
    }
    
    else if(leftChild.head!=NULL&&rightChild.head==NULL){
        ans.head=leftChild.head;
        leftChild.tail->next=ansNode;
        ans.tail=ansNode;
    }
    else if(leftChild.head==NULL&&rightChild.head!=NULL){
        ans.head=ansNode;
        ansNode->next=rightChild.head;
        ans.tail=rightChild.tail;
    }
    else{
        ans.head=leftChild.head;
        leftChild.tail->next=ansNode;
        ansNode->next=rightChild.head;
        ans.tail=rightChild.tail;
    }
    
    return ans;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	 return binaryToLL(root).head;
}

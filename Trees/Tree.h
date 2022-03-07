#include<vector>
using namespace std;

template<typename T>

class TreeNode{
public:
T data;
// Tree itself is formed in T so its ok if we will not specify it as it is default:
vector <TreeNode<T>*> children;           // it is also specifying that this vector is made for TreeNode;

TreeNode(T data){
this->data=data;
}

// we know that vector work as dynamic array so we have to deallocate that vector children;
~TreeNode(){
for(int i=0;i<children.size();i++){
    delete children[i];
}

}


};

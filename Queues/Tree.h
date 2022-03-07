#include<vector>

template<typename T>

class TreeNode{
  public:
      T data;
      // Tree itself is formed in T so its ok if we will not specify it as it is default:
      vector <TreeNode<T>*>  children;

    TreeNode(T data){
    this->data=data;
    }


};

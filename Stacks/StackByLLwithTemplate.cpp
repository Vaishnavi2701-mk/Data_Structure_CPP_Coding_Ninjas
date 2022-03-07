template<typename T>
class Node {
   public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

#include<climits>
template<typename T>
class Stack {
	// Define the data members
    Node <T>*head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        size=0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return head==NULL;
    }

    void push(T element) {
        // Implement the push() function

         Node<T> *newNode=new Node<T>(element);
        newNode->next=head;
        head=newNode;
        size++;
    }

    T pop() {
        // Implement the pop() function
        if(head==NULL){
            return -1;
        }
        T a=head->data;
        Node <T>*temp=head;
        head=head->next;
        delete temp;
        size--;
         return a;
    }

    T top() {
        // Implement the top() function
          if(head==NULL){
            return -1;
        }
        return head->data;


    }
};


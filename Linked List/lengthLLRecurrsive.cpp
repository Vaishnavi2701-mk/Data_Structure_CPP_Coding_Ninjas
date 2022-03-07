#include<iostream>
using namespace std;
#include "TakingInput.cpp"

Node* takeInput_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}
int length(Node *head) {
    // Write your code here

    if(head==NULL){
        return 0;
    }
    return 1+length(head->next);
}



int main() {

	Node *head = takeInput_Better();
	cout<<length(head)<<endl;


}



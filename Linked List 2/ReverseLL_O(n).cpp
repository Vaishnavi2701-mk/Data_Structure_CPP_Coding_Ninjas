#include <iostream>
using namespace std;
#include "TakingInput.cpp"

Node *reverseLL(Node *head){
if(head==NULL || head->next==NULL){
    return head;
}
Node *smallAns=reverseLL(head->next);
Node *tail=head->next;
tail->next=head;
head->next=NULL;
return smallAns;


}


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

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

int main() {

	Node *head = takeInput_Better();
	head = reverseLL(head);
	print(head);



}

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
Node * insertNode(Node *head, int i, int data){
Node *newNode=new Node(data);
Node *temp=head;
int count=0;
// we need to write seperate condition for 0;
if(i==0){
newNode->next=head;
head=newNode;           // now it this condition head is updated;
return head;            //main head is still containing address of previous node which is updated now so return it and change the function type;
}
while(temp!=NULL&&count<i-1){    // hear also;
  temp=temp->next;
  count++;
}
if(temp!=NULL){           // when we gave the index out of range then it shouldn'thave to give the error so add this conditons
Node *a=temp->next;
temp->next=newNode;
newNode->next=a;

// we can finish it in two steps also;
/*newNode->next=temp->next;
temp->next=newNode;*/
}
return head;
}


void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

int main() {

	Node *head = takeInput_Better();
	print(head);
	int i, data;
	cin >> i >> data;
    head=insertNode(head, i, data);   // now it gives us head of changed LL
	print(head);


}



#include <iostream>
using namespace std;


class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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

int fNum(Node * head){

if(head->next==NULL){
    int d=head->data+1;            // we are storing value incremented by 1;
    head->data=d%10;               // if this incremented value is two digit then we have to store unit place wali value;
    return d/10;                   // and then return carry;
}

int ans=fNum(head->next);

int d1=head->data+ans;
head->data=d1%10;
return d1/10;
}

Node *nextNumber(Node * head){

int ans=fNum(head);                // it is giving me carry

if(ans){

  Node *newHead=new Node (1);
  newHead->next=head;
  return newHead;
}

return head;         // if carry is Zero simply return head;

}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head=nextNumber(head);
		print(head);
	}
	return 0;
}

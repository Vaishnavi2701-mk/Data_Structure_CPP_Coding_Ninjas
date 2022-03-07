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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head==NULL){
        return NULL;
    }
    int len=length(head);
    if(n==0){
        return head;
    }
    Node *a=head;
    Node *temp=head;
    Node *b;
    int count=0;
    while(count<len-n){
        b=temp;
        temp=temp->next;
        head=temp;
        count++;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=a;
    b->next=NULL;
    return head;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

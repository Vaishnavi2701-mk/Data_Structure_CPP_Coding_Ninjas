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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head==NULL){
        return NULL;
    }
    int len=length(head);
    Node *temp=head;
    Node *a=temp->next;
    int count=0;
    while(a!=NULL&&count<len){
        if(temp->data!=a->data){
            temp->next=a;
            temp=temp->next;
            a=a->next;
        }
        else{
            a=a->next;
        }
        count++;
    }
    temp->next=NULL;
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}

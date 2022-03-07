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
Node *evenAfterOdd(Node *head)
{
	//write your code here
    Node * oh=NULL;
    Node * ot=NULL;
    Node * eh=NULL;
    Node * et=NULL;
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data%2!=0){
            if(oh==NULL){
                oh=temp;
                ot=temp;
                temp=temp->next;
            }
            else{
                ot->next=temp;
                ot=temp;
                temp=temp->next;
            }

        }
        else{
            if(eh==NULL){
                eh=temp;
                et=temp;
                temp=temp->next;
            }
            else{
                et->next=temp;
                et=temp;
                temp=temp->next;
            }



        }
        }
    if(ot==NULL){
        return eh;
    }
    else if(eh==NULL){
        ot->next=NULL;
        return oh;
    }
    ot->next=NULL;
    et->next=NULL;
    ot->next=eh;
    return oh;
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}

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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *h1=head1;
    Node *h2=head2;
    Node *fh=NULL;
    Node *ft=NULL;
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    if(h1->data<h2->data){
        fh=h1;
        ft=h1;
        h1=h1->next;
    }
    else{
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    while(h1!=NULL&&h2!=NULL){
        if(h1->data<h2->data){
            ft->next=h1;
            ft=h1;
            h1=h1->next;
        }
        else{
            ft->next=h2;
            ft=h2;
            h2=h2->next;
        }
    }
    if(h1!=NULL){
        ft->next=h1;
    }
    else{
        ft->next=h2;
    }
    return fh;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}

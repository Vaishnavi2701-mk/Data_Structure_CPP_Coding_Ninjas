#include <iostream>
using namespace std;
#include "TakingInput.cpp"


int length(Node *head)
{
    //Write your code here
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}


void printIthNode(Node *head, int i)
{
    //Write your code here
    int len=length(head);
    if(i>=len){
        return;
    }
    int index=0;
    while(head!=NULL&&index<i){
      head=head->next;
        index++;
    }
    cout<<head->data<<endl;


}

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}

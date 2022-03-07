#include<iostream>
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

Node *takeinput(){
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
Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head==NULL || pos==0){
        Node *a=head;
        head=head->next;
        delete a;
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    head->next=deleteNodeRec(head->next,pos-1);

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
		int pos;
		cin >> pos;
		head =deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}


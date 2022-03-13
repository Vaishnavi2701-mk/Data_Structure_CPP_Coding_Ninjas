/*
Code: Merge Sort

 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90
*/
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
Node *midPoint(Node *head)
{
    // Write your code here
    if(head==NULL){
        return NULL;
    }
    Node *slow=head;
    Node *fast=slow->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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

Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid=midPoint(head);
    Node *leftPart=head;
    Node *rightPart=mid->next;
    mid->next=NULL;

    Node *sortedLL1=mergeSort(leftPart);
    Node *sortedLL2=mergeSort(rightPart);

    mergeTwoSortedLinkedLists(sortedLL1,sortedLL2);
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}

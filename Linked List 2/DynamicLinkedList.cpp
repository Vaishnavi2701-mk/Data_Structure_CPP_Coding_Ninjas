#include<iostream>
using namespace std;
#include "printLinkedList.cpp"

void print(Node *head){

while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
}

}
int main(){

//dynamic array;
Node *n1=new Node(10);
Node *head=n1;
Node *n2=new Node(20);
Node *n3=new Node(30);
Node *n4=new Node(40);
Node *n5=new Node(50);

n1->next=n2;
n2->next=n3;
n3->next=n4;
n4->next=n5;

print(head);


/*n1->next=n2;  //only n2 because it is pointer itself which carrying the address;//&n2;

cout<<(*n1).next<<" ";*/

}

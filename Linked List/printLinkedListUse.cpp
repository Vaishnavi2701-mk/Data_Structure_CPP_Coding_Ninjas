#include<iostream>
using namespace std;
#include "printLinkedList.cpp"

void print(Node *head){
//while(head->next!=NULL){  this will run only upto 4,so make some changes;
/*Node *temp=head;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
temp=head;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}*/

// lets call print two times;
while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
}
//even after copying it will going to print only once because head tho null chuka hai;
/*while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
}*/
}

int main(){
Node n1(1);
Node *head=&n1;

Node n2(2);
Node n3(3);
Node n4(4);
Node n5(5);

n1.next=&n2;
n2.next=&n3;
n3.next=&n4;
n4.next=&n5;

print(head);
print(head);    // because at every single time head is going to pass its original value;


}

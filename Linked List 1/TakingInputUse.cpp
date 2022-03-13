#include <iostream>
using namespace std;
#include "TakingInput.cpp"

Node * takeInput(){  // it is return type function which returns the address head which is of node type ;
    int data;
    cin>>data;

    Node *head=NULL;    // for now head containing null; because at this point no node is created ;
    while(data!=-1){    // -1 act as a terminator;
        Node *newNode=new Node(data);   // if I will make it statically then it will overwrite the values;
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;             // head ki value tho hume eke hi baar update karni hai so we will use temp to not loss the value of head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    temp->next->next=head;
    return head;
}
void print(Node *head){
while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;        // update the head with address of next element;
    }
}

int main(){

Node *head=takeInput();    //takeInput() function will give us head which is pointer itself; so we should have to receive in pointer as well;
print (head);              // in the linked list always think about head;
}

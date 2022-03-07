#include<iostream>
using namespace std;
#include "QueueFrontRear.h"


int main(){

Deque d(10);
int t;
cin>>t;
while(t--){

int choice, input;

cin>>choice;

switch(choice){
case 1:
    cin>>input;
    d.insertFront(input);
    break;
case 2:
    cin>>input;
    d.insertRear(input);
    break;
case 3:
    d.deleteFront();
    break;
case 4:
    d.deleteRear();
    break;
case 5:
    cout<<d.getFront()<<endl;
    break;
case 6:
    cout<<d.getRear()<<endl;
    break;

}
}


}

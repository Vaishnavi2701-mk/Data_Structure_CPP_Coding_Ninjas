#include<iostream>
using namespace std;
#include "QueueByArray.h"


int main(){

QueueByArray <int> q(5);

q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.enqueue(40);
q.enqueue(50);
q.enqueue(60);


cout<<q.getSize()<<endl;
cout<<q.front()<<endl;

cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;

cout<<q.getSize()<<endl;

cout<<q.isEmpty()<<endl;




}

/*#include<iostream>
using namespace std;
#include "DynamicQueue.h"

int main(){

QueueByArray <int> q(5);

//now it won't show queue is full message;
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




}*/
#include <iostream>
#include <stack>
using namespace std;
void createStack(stack <int> mystack)
{
	stack <int> ms = mystack;
	while (!ms.empty())
	{
		cout << '\t' << ms.top();
		ms.pop();
	}
	cout << '\n';
}
int main()
{
	stack <int> st;
	st.push(32);
	st.push(21);
	st.push(39);
	st.push(89);
	st.push(25);

	cout << "The stack st is: ";
	createStack(st);
	cout << "\n st.size() : " << st.size();
	cout << "\n st.top() : " << st.top();
	cout << "\n st.pop() : ";
	st.pop();
	createStack(st);
	return 0;
}


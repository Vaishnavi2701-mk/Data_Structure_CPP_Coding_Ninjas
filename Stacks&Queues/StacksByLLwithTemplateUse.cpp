#include<iostream>
using namespace std;
#include "StackByLLwithTemplate.cpp"



int main(){

Stack <char>s;

s.push(100);
s.push(101);        // This are the ascii values representing characters.....
s.push(102);
s.push(103);


cout<<s.getSize()<<endl;

cout<<s.top()<<endl;

cout<<s.pop()<<endl;
cout<<s.pop()<<endl;

cout<<s.top()<<endl;

cout<<s.getSize()<<endl;

cout<<s.isEmpty()<<endl;



}

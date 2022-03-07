#include<iostream>
#include<cstring>
using namespace std;
#include "copyConstructordeepcopy.cpp"


int main(){
char name[]="abcd";
Student s1(20,name);
s1.display();
Student s2(s1);
s2.name[0]='x';   // it is calling the the name which is in the class so we have to make it a public;
s2.display();

s1.display();   // here s2 is copy of s1 and thats why copy constructor is called here and inbuilt copy constructor does the shallow copy;

// after deep copy it will be fine;
}

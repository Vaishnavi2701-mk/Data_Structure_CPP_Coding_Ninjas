#include<iostream>
#include<cstring>
using namespace std;
#include "shallow_deep_copy.cpp"


int main(){

    char name[]="abcd";
Student s1(20,name);
s1.print();
name[3]='e';
Student s2(24,name);
s2.print();
s1.print();  // it should have to print abcd but it is going to print abce because of shallow copy;

             // after deep copy it will print abcd again;

}

#include<iostream>
using namespace std;
#include "Student2.cpp"

int main(){
cout<<"User define Constructor:\n"<<endl;
Student s1;
s1.display();
Student *s2=new Student;
s2->display();
cout<<"\nParameterized constructor:"<<endl;
Student s4(57);
s4.display();

Student *s5=new Student(19,1003);
cout<<s5<<endl;  // it will also show the address;
s5->display();


}

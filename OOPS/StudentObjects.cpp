#include<iostream>
using namespace std;
#include "Student.cpp"   //we have to include the file in which we had created a class;

int main(){

// Creating objects statically;

Student s1;
Student s2;
Student s3,s4,s5;


// filling the information;

s1.rollNumber=83;
s1.age=19;           //This happens because I made age as private;
cout<<s1.rollNumber<<endl;
cout<<s1.age<<endl;

// Creating Objects Dynamically;

Student *s6=new Student();//  we could give the parenthesis or not ,no matter;

// filing the information;

(*s6).rollNumber=34;
(*s6).age=102;
cout<<(*s6).rollNumber<<endl;
cout<<(*s6).age<<endl;

// another way of creation;
s6->age=34;
s6->rollNumber=102;
cout<<s6->age<<endl;
cout<<s6->rollNumber<<endl;


}

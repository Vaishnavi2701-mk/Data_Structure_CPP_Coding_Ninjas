#include<iostream>
using namespace std;
#include "Student1.cpp"

int main(){
Student s1;
Student s2;

s1.rollNumber=104;
//s1.age=23; because it is private we cant access;
s1.display();
s2.display();   // even if the age is private but we can access it by using  functions;
// output;
// 0 104
// 0 36565   because I didn;t set any for age in the class so randomly it is showing 0 but set the roll number for s1 so it is visible didn,t set for s2 so random;
Student *s3=new Student;
(*s3).rollNumber=34;
s3->display();

cout<<"S1 age:"<<s1.getAge()<<endl;
cout<<"S3 age:"<<s3->getAge()<<endl;

s1.setAge(23);
s2.setAge(19);           //setAge() function taking an argument and setting an age , so after setting call display;
//(*s3).setAge(45);
s3->setAge(45);
s1.display();
s2.display();
s3->display();


}

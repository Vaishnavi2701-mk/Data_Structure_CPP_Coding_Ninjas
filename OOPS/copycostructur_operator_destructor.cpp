#include<iostream>
using namespace std;
#include "Student2.cpp"

int main(){

    //copy constructor;
/*Student s1(19,83);
s1.display();
Student s2(s1);
s2.display();

Student *s3=new Student(15,1007);
s3->display();


Student s4(*s3);

Student s5(s2);
Student *s6=new Student(*s3);

Student *s7=new Student(s2);*/

//copy assignment operator;

/*Student s1(19,83);
cout<<"s1:"<<endl;
s1.display();
Student s2(23,156);
cout<<"s2:"<<endl;
s2.display();

s2=s1;
cout<<"After ;s2:"<<endl;
s2.display();*/

//Destructor;

Student s1(19,420);
Student s2(34,564);

Student *s3=new Student(15,7889);

Student s5=s2;  //copy constructor;
s5.display();

delete s3;   //s3 is in heap memory so delete it manualy;

}

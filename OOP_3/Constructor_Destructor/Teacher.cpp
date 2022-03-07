#include<iostream>
using namespace std;

class Teacher{

public:
   void print(){
    cout<<"Teacher"<<endl;
    }
};

class Student{

};

class TA: public Teacher,public Student{

};

#include<iostream>
using namespace std;

class Student{
public:
    int age;
    int const rollNo;
    int &x;           //reference variable of age;
    // use initialization list;
    Student (int r,int age): rollNo(r),age(age),x(this->age){    // if I will write x(age) this will be wrong because x is the reference variable of data memory age;

    }
};
int main(){

Student s1(1001,20);    // here it will give error because we didn't set constant roll number;

}

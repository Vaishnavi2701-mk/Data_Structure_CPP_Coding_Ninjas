#include<iostream>
using namespace std;
 class Student{
 public:
 char *name;
 int rollNum;

 Student(int r){
  rollNum=r;
 }
 void print(){
     cout<<name<<" "<<rollNum<<endl;

 }

 };
 int main(){
 //Student *s1=new Student();  // it is calling built-in constructor which is vanished now
 Student *s1=new Student(12);
 s1->name="dt";
 s1->rollNum=12;
 s1->print();
 }

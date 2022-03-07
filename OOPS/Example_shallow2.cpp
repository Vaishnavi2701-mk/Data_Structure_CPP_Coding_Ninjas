#include <iostream>
using namespace std;

class Student{
    public :
        char *name;
        int rollNo;
                              // no constructor that means it is going to use built in constructor;
        void print(){
            cout << name << " "  <<  rollNo << " ";
        }
};

int main() {
    char name[] = "Misha";
    Student s1;
    s1.name = name;
    s1.rollNo = 101;
    //s1.print();  if print here Misha then;

    name[0] = 'N';
    Student s2;
    s2.name = name;
    s2.rollNo = 102;

    s1.print();      //  both are going to change because of change in string and we are not copying out string there;
    s2.print();
}
/* output

 Nisha 101 Nisha 102*/

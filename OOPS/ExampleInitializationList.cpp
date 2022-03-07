#include<iostream>
using namespace std;

class Student {
    public :

    const int rollNumber;
    int age;

    int &x;                         // whenever we generate reference variable we need to initialize it as well, because it will confuse that it is reference of which;

    Student(int r, int a) : rollNumber(r), age(a),x(this->age) {
    }
};


int main() {
    Student s1(100, 23);
   // s1.x = age;                     // We didn't initialize the reference variable and now we are trying to use it which is invalid;
    cout << s1.rollNumber << " " << s1.age << " " << s1.x;
}

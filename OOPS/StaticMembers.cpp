#include <iostream>
using namespace std;

class Student{
    static int totalStudents;//  as we are talking about functions make it in private;
public:

int rollNo;
int age;
//static int totalStudents;   // total student shouldn't be the property of every student; so make it static;
// static variables or functions are only available to classes;

//Now I want that student Number should have to increase as student object is created;
// so as Objects are going to made constructor will call itself;
Student(){
totalStudents++;
}

int getrollNo(){
return rollNo;
}     // we cant make it static because it is depend upon object as we are talking about roll number;

static int gettotalStudents(){    // as it is static property we can make it static function;
//return rollNo;                  // static function only works with static properties; and don't have the "this" because it is not working with objects
return totalStudents;
}

};
int Student::totalStudents=2;   // initialization of static properties outside the class;
int main(){

/*Student s1;
Student s2;

cout<<s1.rollNo<<" "<<s1.age<<endl;
cout<<Student::totalStudents<<endl;  // accessing the static properties;
cout<<s1.totalStudents<<endl;     // logically incorrect but compiler allow this;

 s1.totalStudents=20;            // even though static properties are not depend on objects but we can make changes by using objects;
 Student s3;
 cout<<s3.totalStudents<<endl;
 cout<<Student::totalStudents<<endl;*/

 Student s1;
 Student s2,s3,s4,s5;
 //cout<<Student::totalStudents<<endl;  now totalStudent is private property;
 cout<<Student::gettotalStudents()<<endl;  // it will going to add as it is 5 objects but we initially initialize as 2 so 7;

}

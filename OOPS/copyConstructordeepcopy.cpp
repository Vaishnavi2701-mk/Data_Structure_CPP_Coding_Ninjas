class Student{
int age;
public:
    char *name;
    Student (int age, char *name){
    this->age=age;
    this->name=new char(strlen(name)+1);
       strcpy(this->name,name);
    }
// own copy constructor;
Student (Student const&s){ // it is similar to s1;
this->age=s.age;
this->name=new char(strlen(s.name)+1);
strcpy(this->name,s.name);


}
  void display(){

  cout<<age<<" "<<name<<endl;

  }



};



class Student{
public:
    int rollNumber;
private:
    int age;

public:
    void display(){
    cout<<age<<" "<<rollNumber<<endl;
    }
    Student(){

    cout<<"Constructor no.1"<<endl;}  // if I am going to comment it out then first is that our built in function is vanished now so when object try to call this one it will throw an error;
    /*Student(int r){
    cout<<"Constructor no.2"<<endl;
    rollNumber=r;
    }*/
    Student (int rollNumber){
      this-> rollNumber=rollNumber;      //this time constructor is going to confuse that what to display;......we need to use "this" keyword;
      // "this" pointing towards the address of particular object so we need to use it as pointer;
        }
    Student (int a, int r){
    cout<<"Constructor no.3"<<endl;
    cout<<this<<endl;            // this will display the address of the object for which this constructor is going to use;
    age=a;
    rollNumber=r;
    }
    ~Student(){
        cout<<"Destructor called!"<<endl;
    }

};

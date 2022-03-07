#include<iostream>
using namespace std;

class Vehicle1{
public:

    Vehicle1(){
    cout<<"Vehicle Default Constructor: "<<endl;
    }

    ~Vehicle1(){
    cout<<"Vehicle Default Destructor: "<<endl;
    }

    void print(){
      cout<<"Vehicle"<<endl;
    }


};

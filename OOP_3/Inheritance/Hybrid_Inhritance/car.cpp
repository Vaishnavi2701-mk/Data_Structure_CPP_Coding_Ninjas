#include<iostream>
using namespace std;
#include"Vehicle.h"

class Car: public Vehicle{

public:
       Car(){
    cout<<"Car Default Constructor: "<<endl;
    }

    ~Car(){
    cout<<"Car Default Destructor: "<<endl;
    }

    void print(){
      cout<<"Car"<<endl;
    }

};

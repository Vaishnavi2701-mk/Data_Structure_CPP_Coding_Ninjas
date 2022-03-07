#include<iostream>
using namespace std;

class Vehicle{

public:

//pure virtual function
  virtual  void print()=0;
};

// Now Vehicle becomes abstract class

class Car: public Vehicle{

public:

 /*  void print(){
    cout<<"Car: "<<endl;
    }*/

};

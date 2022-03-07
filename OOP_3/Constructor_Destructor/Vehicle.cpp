#include<iostream>
using namespace std;

class Vehicle{

public:
Vehicle(){
cout<<" vehicle constructor: "<<endl;
}
Vehicle(int z){
cout<<" parametrize vehicle constructor:"<<endl;
}
~Vehicle(){
cout<<" vehicle destructor: "<<endl;
}

};

/*class Car: public Vehicle{
public:
//Car():Vehicle(5){     it is calling parametrize constructor
//Car(int x):Vehicle(x)   // this time we have to pass argument in object itself;
Car(){
cout<<" Car constructor: "<<endl;
}
Car(int x):Vehicle(5){
cout<<" Car parametrize constructor: "<<endl;
}
~Car(){
cout<<" Car destructor: "<<endl;
}

};

class Honda : public Car{

public:
Honda(int x,int y){
cout<<" Honda constructor: "<<endl;
}
~Honda(){
cout<<" Honda destructor: "<<endl;
}

};*/

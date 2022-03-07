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

void print(){
cout<<"Vehicle"<<endl;
}

};

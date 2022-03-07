#include<iostream>
using namespace std;
#include"Vehicle.cpp"



int main(){

Vehicle v;

//v.maxSpeed=5;       private so not accessible;
//v.numTyres=6;       protected  --- " -----
v.colour="black";



Car c;
//c.numTyres=4;  only car can use it but not its objects;because it is protected
//c.colour="Blue";
c.numGears=8;
//c.maxSpeed=9;  private------"-----------
c.print();
}

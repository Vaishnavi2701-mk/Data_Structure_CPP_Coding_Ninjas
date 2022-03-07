#include<iostream>
using namespace std;
#include "DynamicArray.cpp"


int main(){

DynamicArray d1;

d1.add(10);
d1.add(20);
d1.add(30);
d1.add(40);
d1.add(50);
d1.add(60);

d1.print();
//cout<<d1.getElement(2);

/*d1.add(2,200);
d1.print();*/

DynamicArray d2(d1);        //built in copy constructor do the shallow copy;

DynamicArray d3;
d3=d1;
d1.add(4,170);
d2.print();                     // built it copy assignment operator that also allow the shallow copy;
d3.print();
d1.print();

}

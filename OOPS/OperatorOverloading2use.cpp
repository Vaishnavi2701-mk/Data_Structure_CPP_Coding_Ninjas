#include<iostream>
using namespace std;
#include "OperatorOverloading2.cpp"


int main(){
Fraction f1(10,2);
Fraction f2(15,4);

f1.print();

//++f1;  // operator call;

//Fraction f3=++f1;  // here we are putting the value of f1 into f3 so we have to return it thus make the function of return type;

//++(++f1);  // it ts again returning the value of f1 and incrementing it so need m=to make return type function which we had already done;

           // but it will not going to increment it  again;

Fraction f3=++(++f1);   // in case of function it will give proper incremented value; because of buffering copy; but I don't want to create a copy; so make the changes in the classes;
f3.print();
f1.print();
//f3.print();
 // dereferencing the function will solve the all problem;
}

#include<iostream>
using namespace std;
#include "Fraction.cpp"

int main(){

Fraction f1(10,2);
Fraction f2(15,4);

f1.add(f2);

f1.print();
f2.print();

f1.multiply(f2);
f1.print();
f2.print();

Fraction const f3;
cout<<f3.getNumerator()<<f3.getDenominator()<<endl;  // this will also going to give an error because constant objects can call the constant functions only;

cout<<f3.setNumerator()<<endl;     // even if I am going to make it constant it will call the function but further it will give me an error;

}

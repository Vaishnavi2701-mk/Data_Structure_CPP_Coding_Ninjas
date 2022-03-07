#include<iostream>
using namespace std;
#include "operatorOverloading.cpp"


int main(){

Fraction f1(10,2);
Fraction f2(10,2);

Fraction f3=f1.add(f2);

Fraction f4=f1+f2;   // it will call operator ;
Fraction f5=f1*f2;

f1.print();
f2.print();
f3.print();

f4.print();
f5.print();

if(f1==f2){            // check operator will use itself automatically
    cout<<"Equal"<<endl;
}
else
    cout<<"Not equal"<<endl;


}

#include<iostream>
using namespace std;
#include "OperatorOverloading3.cpp"


int main(){

int i=5,j=3;
(i+=j)+=j;
cout<<i<<" "<<j<<endl;

Fraction f1(10,2);
Fraction f2(15,4);

/*f1+=f2;

f1.print();
f2.print();*/

(f1+=f2)+=f2;  //  it will give an error if we didn't make the return type;
f1.print();
f2.print();


/*Fraction f3=f1++;    // it will obviously require return type;

f3.print();
f1.print();*/



}
 // in post increment no nesting;

#include<iostream>
using namespace std;
#include "Template2.cpp"

int main(){

Pair <int,double> p1;

p1.setX(10.345);    // here I am passing double but we had create x as integer so it will only execute 10;
p1.setY(20.222);

cout<<p1.getX()<<" "<<p1.getY()<<endl;

Pair <double,char> p2;

p2.setX(13.34);
p2.setY('a');

cout<<p2.getX()<<" "<<p2.getY()<<endl;


}


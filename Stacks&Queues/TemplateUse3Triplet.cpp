#include<iostream>
using namespace std;
#include "Template2.cpp"

int main(){

Pair <Pair<int, int>,int> p1;
p1.setY(10);
Pair <int,int>p4;
p4.setX(20);
p4.setY(30);
p1.setX(p4);

cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;

Pair <int,Pair<int,double>> p2;
p2.setX(20);
Pair <int,double> p5;
p5.setX(30);
p5.setY(24.56);
p2.setY(p5);

cout<<p2.getX()<<" "<<p2.getY().getX()<<" "<<p2.getY().getY()<<endl;


}


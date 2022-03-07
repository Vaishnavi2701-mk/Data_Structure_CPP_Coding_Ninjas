#include<iostream>
using namespace std;

void g(int const &a){
a++;       // nahi hoga but;extra storage tho nhi banni;
}

void f(int const*p1){

(*p1)++;    // it is pointing towards a variable which is considered as constant so  iske through change nahi hoga;


}
int main(){

int j=12;
int *p=&j;
f(p);
}

#include<iostream>
using namespace std;

int a=10;   // now my a is global variable, so whatever the changes will be there it will reflect in whole code;
void g(){
a++;
cout<<a<<endl;

}
void f(){
cout<<a<<endl;
a++;
g();
}
int main(){
a=10;
f();
cout<<a<<endl;


// thats why we will never use global variable concept because it violates the conditions for functions;
}

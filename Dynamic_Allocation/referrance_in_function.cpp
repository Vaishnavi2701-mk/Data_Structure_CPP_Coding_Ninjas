#include<iostream>
using namespace std;
//void increment(int n)//here a new variable is created with new address so whatever the changes here will not reflect in main
void increment(int &n) {       // now n is reference variable of i ; so whatever the changes ; it will reflect in main
n++;
}
// bad practice;
int &f(int n){
int a=20;
return a;
}
// bad practice
int *f2(){
int i=10;
return &i;
}
int main(){

int i=20;
int &k=f(i);      // k is reference of function,but after function calling ends memory will but vanished ,but yes we can access it through k;
int *p=f2();      // same// local variables;
increment(i);
cout<<i<<endl;

}

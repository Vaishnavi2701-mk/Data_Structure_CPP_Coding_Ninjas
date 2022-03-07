#include<iostream>
using namespace std;

int main(){

int i=10;
int j=12;
int const*p=&i;
p=&j;      // pointer is constant itself ,so it can store different values;
(*p)++;    // but towards which it is pointing is constant;
int *const p1=&i;
(*p1)++;   // now pointer is constant itself so it can make changes with respect to variable value;
p1=&j;     // but it cant store new values in itself;

int const*const p3=&j;
p3=&i;      // now both are constant so we cant do anything;
(*p3)++;
}

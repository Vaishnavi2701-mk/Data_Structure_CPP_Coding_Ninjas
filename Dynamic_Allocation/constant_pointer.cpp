#include<iostream>
using namespace std;

int main(){
int const i=10;
//int *p=&i;       // pointer can make the changes in the same storage,so invalid;

int const i2=10;
//int const *p2=&i2;  // no error because pointer is pointing towards constant int;

//(*p2)++;      // nahi hoga;

int j=12;
int const *p3=&j;   // even though variable is not constant I am saying that pointer is pointing towards  constant so iske through changes nahi honge;n
cout<<*p3<<endl;
j++;
cout<<*p3<<endl;
(*p3)++;      // it will give me error
cout<<*p3<<endl;

}

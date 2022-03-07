#include<iostream>
using namespace std;

int main(){

int a[10];
cout<<a<<endl;
cout<<&a<<endl;
cout<<&a[0]<<endl;  // this three will give the address with respect to 0th index;
a[0]=4;
a[1]=7;
a[3]=5;
cout<<*a<<endl;      // because a contain address of 0th index initially;
cout<<*(a+1)<<endl;   // next index ki value;
cout<<1[a]<<endl;    //similar to a[1];
// difference in size;

int *p=&a[0];
cout<<sizeof(a)<<endl;      //it is working according to own address but didn't create different memory;
cout<<sizeof(p)<<endl;      // pointer create different block of 8 bytes for itself and then storing address of other arrays;

// difference while using & operator;

cout<<&a<<endl; // array works like a pointer but it didn't create different block for itself so address with respect to 0th index;
cout<<a<<endl;
cout<<p<<endl;   // here pointer contain address of array a[0] so it will print that address ;
cout<<&p<<endl;  // here it will print its own address;

*p=a[3];
cout<<*p<<endl;  // we can store address of any element of array in pointer;
//a=a+3;         this will be the wrong operation
p=a;             // we can store address of array in pointer;
cout<<p<<endl;
//a=p;             // we cannot store pointer address in array;
//cout<<a<<endl;


}

#include<iostream>
using namespace std;

int main(){
/*int i=10;
cout<<i<<endl;
cout<<"Address "<<&i<<endl;//to print the address use & in-front of variable;

int *p=&i;                 // to store a particular address ,here using pointer;
cout<<"Address "<<p<<endl;

float f=56.3;
float *pf=&f;
cout<<pf<<endl;

double d=434.23;
double *pd=&d;
cout<<pd<<endl;


// to access value with respect to particular variable through

cout<<*p<<endl;  // it will give same as i;
// not fixed size but vary differently ;
cout<<sizeof(p)<<endl;
i++;
cout<<i<<endl;   // it will going to increment in both because i and *p both are same;
cout<<*p<<endl;
(*p)++;          // it will also act as a integer,and affect on both i and *p;
cout<<i<<endl;
cout<<*p<<endl;

int a=i;//*p     // here I am copying the value of i in a;
a++;             // but only increment in a;which is different storage;
cout<<a<<endl;
cout<<i/*p*//*<<endl; // so no change in i;

int *q=p;             // q is a new pointer which is storing the value of p pointer; so now i,*p and *q are same;
cout<<*q<<endl; */

int i;
cout<<i<<endl;
i++;
cout<<i<<endl;


int *p=0;        // save from the risk;
//int *p;        // pointer contain any garbage address;
cout<<p<<endl;  //print random address ;
cout<<*p<<endl;  //access value with respect to that random address;
(*p)++;
cout<<*p<<endl;

int a=10;
int *pr=&a;
cout<<pr<<endl;


}

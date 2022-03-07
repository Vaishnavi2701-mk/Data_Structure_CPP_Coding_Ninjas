#include<iostream>
using namespace std;

int main(){

int a[]={1,2,3,4};
char c[]="abcd";
cout<<a<<endl;
cout<<c<<endl;   // character array will print directly the content of array;

char *p=&c[0];
cout<<p<<endl;   // pointer pointing towards character array will also print the content;

char c1='a';
char *p1=&c1;

cout<<c1<<endl;
cout<<p1<<endl;   // it is pointing towards character variable ,so it will execute until it will find null;


char str[]="abcde";
char *p2="abcde";       // it is pointing towards the same string which char array str contain; it will be risky; we will avoid it;
cout<<p2<<endl;N

}

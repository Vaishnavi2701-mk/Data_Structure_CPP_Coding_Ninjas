#include<iostream>
using namespace std;
#define PI 3.14

int main(){

int r;
cin>>r;

//cout<<3.14*r*r<<endl;// but what if ,i want to use 3.14 again and again;
// then I will create double to store 3.14

//double pi=3.14;// but still here are two problems; 1; extra storage for pi;2; if someone changes pi=pi+1; like that then my whole code will be wasted
//so that's why we will use macros #define ,so it is one instruction, that whole compiler will see at every single time;

cout<<PI*r*r<<endl;


}

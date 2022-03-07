#include<iostream>
using namespace std;

int main(){
int const i=10;
//i=12; because my variable is constant I cant change it;

//int const i;
//i=10;  error i is not initialized and filled  with garbage value which cant change

//reference
//1. when reference variable is constant
int j=12;
int const &k=j;
//k++;  // k is reference but it is constant so we cant change j through k;
j++;
//2.when both are the constant;
int const j2=12;
int const &k2=j;
k2++;
j2++;   // both will give the error because both paths are constant;/
//3.reference by non-constant variable
int const j3=12;
int &k3=j3;      // reference variable could make the changes which is invalid;
}

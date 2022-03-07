#include<iostream>
using namespace std;

int main(){

int *p=new int;
*p=10;
cout<<p<<endl;
cout<<*p<<endl;

double *pd=new double;
char *pc=new char;

int *pa=new int [50];
int n;
int *pa2=new int [n];      // now with the help of heap memory we can actually create a array of n variable size;
cout<<"Enter the number of elements: "<<endl;
cin>>n;
for(int i=0;i<n;i++){
    cin>>pa2[i];
}
int max=-100000;
for(int i=0;i<n;i++){
    if(max<pa2[i]){
        max=pa2[i];
    }
}
cout<<max;
}

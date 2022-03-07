#include<iostream>
using namespace std;

int main(){

int i;
i=10;
int j=i;    // here j is different variable with different address, it is only copying tShe value of i;
i++;
cout<<j<<endl;  // that's why when we execute j there will be no changes;

//Reference Variable
int &j1=i;
/*int &j1;
j1=i;*/ //this will give me error, because I am declaring j as a reference variable but of whom; that should I have to give in front of it;
i++;
cout<<j1<<endl;
j1++;              // here both j and i are now have the same memory so, even if one changes it will affect other;
cout<<i<<endl;
int k=20;
j1=k;
cout<<i<<endl;
cout<<j1<<endl;


}

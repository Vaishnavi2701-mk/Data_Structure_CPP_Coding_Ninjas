#include<iostream>
using namespace std;

int main(){

//char c='A';
char c[]="abcd";

/*int i=c;
cout<<i<<endl;*/

char *pc=&c[0];
int *p=(int*)pc;
cout<<*p<<endl;          // now it is an integer it contain 3 extra bytes co collectively with that 4 bytes it will give an integer number
cout<<*(p+1)<<endl;
cout<<*(p+2)<<endl;
cout<<*(p+3)<<endl;
cout<<pc<<endl;           // character pointer it is, so execute up-to null
cout<<p<<endl;            // collective number jo banaya hai uska address dega
}

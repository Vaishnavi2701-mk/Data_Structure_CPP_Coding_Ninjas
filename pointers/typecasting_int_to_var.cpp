#include<iostream>
using namespace std;

int main(){
/*int i=65;
char c=i;           //implicit typecasing;
cout<<c<<endl;*/
int i[4]={1,2,3,4};

int *p=&i[0];
//char *pc=p;   p already read the address in 4 bytes as integer; now I am trying to read that integer address as character; it is not making a sense;
//we need to typecast it explicitly
char *pc=(char*)p;
cout<<*p<<endl;
cout<<*pc<<endl;    // now it will read only 1 byte i.e, 65 and execute 'A'

cout<<*(pc+1)<<endl;   // it will all give me null;
cout<<*(pc+2)<<endl;
cout<<*(pc+3)<<endl;

cout<<p<<endl;
cout<<pc<<endl;





}

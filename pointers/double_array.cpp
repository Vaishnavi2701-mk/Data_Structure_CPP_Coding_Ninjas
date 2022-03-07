#include<iostream>
using namespace std;

void increament1(int **p2){
p2=p2+1;
cout<<p2<<endl;
}
void increament2(int **p2){
*p2=*p2+1;
cout<<*p2<<endl;

}
void increament3(int **p2){
**p2=**p2+1;
cout<<**p2<<endl;

}

int main(){
int i=10;
int *p=&i;
int **p2=&p;

cout<<p2<<endl;         // double pointer which contain the address of pointer p;
cout<<&p<<endl;
cout<<endl;
cout<<*p2<<endl;
cout<<p<<endl;
cout<<&i<<endl;
cout<<endl;
cout<<**p2<<endl;
cout<<*p<<endl;
cout<<i<<endl;
cout<<endl;
cout<<p2<<endl;
increament1(p2);     // contain address of pointer in double pointer which is not going to change;
cout<<p2<<endl;
cout<<endl;
cout<<*p2<<endl;
increament2(p2);      // contain address of variable i as value of pointer ,so it will affect the changes
cout<<*p2<<endl;
cout<<endl;
cout<<**p2<<endl;
increament3(p2);      // contain value of variable i,which will affect the changes;
cout<<**p2<<endl;
}

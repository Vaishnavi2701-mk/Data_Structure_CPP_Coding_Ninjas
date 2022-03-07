#include<iostream>
using namespace std;

void print(int *p){

cout<<*p<<endl;


}
void increametAddress(int *p){

p=p+1;
cout<<p<<endl;

}
void incrementValue(int *p){
(*p)++;
cout<<*p<<endl;
}

int main(){
int i=10;
int *p=&i;
cout<<p<<endl;
print(p);
increametAddress(p);
cout<<p<<endl;         // even after calling function there is no change in address of pointer in main;
cout<<*p<<endl;
incrementValue(p);
cout<<*p<<endl;       // changes in value with respect to array reflects in main;
}

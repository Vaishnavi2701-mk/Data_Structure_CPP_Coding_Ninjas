#include<iostream>
#include"Vehicle.cpp"
using namespace std;

/*   Function/Method overloading

int test(int a, int b){

}

int test(int a){
}
int test(){

}
void test(){
}
*/
int main(){

// it cannot create object of Vehicle as it become abstract
//Vehicle v;
Car c;  // This time Car as an derived class doesnt complete pure virtual function it also becomes abstract ;
/*v.print();
c.print();

Vehicle *v1=new Vehicle;

v1->print();

Vehicle * v2;

//although it is pointing towards Car class but still it is an object of Vehicle;
v2=&c;

v2->print();*/

}

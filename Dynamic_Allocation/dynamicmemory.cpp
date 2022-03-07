#include<iostream>
using namespace std;


int main(){
/* for this our static memory knows that this all kind of work ids going for a variable i, so there will no new memory for i and all kind of work is going
to happen in the same memory,and when the scope ends the memory will automatically released
while(true){
    int i=10;
}*/

/* here there is no variable for heap memory, so in every iteration it will create a new storage in heap memory and now pointer is pointing towards a new storage
but there is wastage of memory ,so we have to manually delete it;
while(true){
    int *p=new int ;
}*/

int *p=new int;
delete p;        // here we are not deleting the pointer ,we are deleting the memory towards which it is pointing
cout<<p<<endl;  // after deleting the memory and then if I am not modifying the pointer with new value it is then pointing towards the same address
/*p= new int;      // and now putting new address
delete p;
p=new int[50];
delete []p;      // syntax to delete array;*/





}

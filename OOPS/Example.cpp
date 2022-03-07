#include<iostream>
using namespace std;
 class Box{
 public:
     int length;
     int height;
     int breadth;

    void getVolume(){
     cout<<length*breadth*height;
    }
 };
int main(){
Box b1;
b1.height=4;
b1.length=5;
b1.getVolume();   // it will give the garbage value because breadth is not initialized and it will use its garbage value so it will be going to a garbage value;

}

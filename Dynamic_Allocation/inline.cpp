#include<iostream>
using namespace std;

inline int max(int a,int b){  // here is the inline
return (a>b)?a:b;
}
int main(){

int a,b;
cin>>a>>b;
//to find maximum between two;
/*int c;
if(a>b){
    c=a;
}
else{
    c=b;
}*/
// instead of this we can use tertiary operator
/*int c=(a>b)?a:b;
cout<<c<<endl;

int x=34,y=32;
int z=(x>y)?x:y;
cout<<z<<endl;*/ //here everything is ok but I am doing one thing repeatedly;so apply function

int c=max(a,b);
cout<<c<<endl;

int x=34,y=32;
int z=max(x,y);
cout<<z<<endl;   // here still a one problem; our code readability is best but problem hit will be there;
                 // we can solve this problem by making a function inline;

}

#include<iostream>
using namespace std;

bool checkNumber(int a[],int n,int x){
if(n==0){
    return false;
}
if(a[0]==x){
  return true;
}
bool nextElement=checkNumber(a+1,n-1,x);
return nextElement;
}
int main(){
int a[5]={1,2,3,4,5};
int x;
cout<<"Enter the integer:"<<endl;
cin>>x;
cout<<checkNumber(a,5,x)<<endl;
}

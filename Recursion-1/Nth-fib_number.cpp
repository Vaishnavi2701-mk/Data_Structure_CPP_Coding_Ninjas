#include<iostream>
using namespace std;
int fib(int n){
if(n==0){
    return 0;
}
if(n==1){
    return 1;                 // in this problem  we need two base conditions because demand is there
                              // eg. our nth term is sum of previous two, 2-->1+1(firstTerm+secondTerm)
}
int firstTerm=fib(n-1);
int secondTerm=fib(n-2);
return firstTerm+secondTerm;

}
int main(){
    int n;
    cout<<"Enter the nth term:"<<endl;
    cin>>n;
cout<<"Ans: "<<fib(n)<<endl;
}

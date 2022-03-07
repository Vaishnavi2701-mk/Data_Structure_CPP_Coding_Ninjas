#include<iostream>
using namespace std;

int countZeros(int n){
if(n==0){
    return 1;
}
if(n<10){
    return 0;
}
int digit=n%10;
if(digit==0){
    return 1+countZeros(n/10);
}
return countZeros(n/10);

}
int main(){
int n;
cout<<"Enter the integer: "<<endl;
cin>>n;
cout<<countZeros(n)<<endl;
}

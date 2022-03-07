#include<iostream>
using namespace std;

int sumOfDigit(int n){
if(n==0){
    return 0;
}
int digit=n%10;
int ans=digit+sumOfDigit(n/10);
return ans;
}

int main(){
int n;
cout<<"Enter the number: "<<endl;
cin>>n;
cout<<"Ans: "<<sumOfDigit(n)<<endl;
}

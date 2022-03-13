#include<iostream>
using namespace std;

int factorial(int n){
cout<<n<<endl;
if(n==0){
    return 1;
}
int smallOutput=factorial(n-1);  // to find a factorial of "n" we have the simple formula like; n!=n*(n-1)!; so function call repeated until it gives a factorial of (n-1);
                                 //we always have to provide base condition; think reverse;
return n*smallOutput;

}

int main(){
int n;
cin>>n;
int output=factorial(n);
cout<<output<<endl;

}

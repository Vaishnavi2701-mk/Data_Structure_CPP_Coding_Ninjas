/* 
Sum Of Digit(Recursive)
Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9*/

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

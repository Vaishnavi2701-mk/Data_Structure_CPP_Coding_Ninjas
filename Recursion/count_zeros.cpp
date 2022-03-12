/* 
Count_Zeros

Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.
Input format :
Line 1 : Integer M
Line 2 : Integer N
Output format :
M x N
Constraints :
0 <= M <= 1000
0 <= N <= 1000
Sample Input 1 :
3 
5
Sample Output 1 :
15
Sample Input 2 :
4 
0
Sample Output 2 :
0
*/

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

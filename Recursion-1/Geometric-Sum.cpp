/*
Geometric Sum
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500
Sample Input 2 :
4
Sample Output 2 :
1.93750
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k){

if(k==0)
    return 1;
  double ans=1/(double)pow(2,k)+geometricSum(k-1);
  return ans;
}
int main(){
int k;
cout<<"Enter k: "<<endl;
cin>>k;
cout<<geometricSum(k)<<endl;
}

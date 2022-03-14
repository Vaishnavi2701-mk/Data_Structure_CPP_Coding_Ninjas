/*
Code : No. of balanced BTs

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include<iostream>
#include<cmath>
using namespace std;

/*brute force
int balancedBSTs(int h){

if(h<=1){
    return 1;
}

int x= balancedBSTs(h-1);
int y= balancedBSTs(h-2);

int mod=(int)(pow(10,9)+1);

int temp1=(int)(((long)(x)*x)%mod);
int temp2=(int)((2*(long)(x)*y)%mod);

int ans=(temp1+temp2)%mod;
return ans;
}*/

//DP
int balancedBSTs(int h){

int dp[h+1];
dp[0]=1;
dp[1]=1;

int mod=(int)(pow(10,9)+1);

for(int i=2;i<=h;i++){

    dp[i]=(int)(((long)dp[i-1]*dp[i-1])%mod)+((2*(long)dp[i-1]*dp[i-2])%mod)%mod;
}

return dp[h];

}
int main(){
int h;
cout<<"Enter the height h: "<<endl;
cin>>h;
cout<<balancedBSTs(h);
}

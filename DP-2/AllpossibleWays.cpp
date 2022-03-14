/*
All possible ways

Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Input Format:
The first line of input contains two space separated integers, that denote the value of a and b.
Output Format:
The first and only line of output contains count of ways in which a can be represented as sum of unique integers raised to power b.
Constraints :
1 <= a <= 10^4
1 < b <= 20
Time Limit: 1 second
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
*/

#include <iostream>
using namespace std;
#include<cmath>
int getAllWays(int a,int b,int curNo,int *dp){
    if(a<0){
        return 0;
    }
    if(a==0){
        return 1;
    }

    int ans=0;

    for(int i=curNo;pow(i,b)<=a;i++){
            ans+=getAllWays(a-pow(i,b),b,i+1,dp);
    }
    dp[a]=ans;
    return ans;
}
int getAllWays(int a, int b) {
      int dp[100000];
    for(int i=0;i<100000;i++){
        dp[i]=-1;
    }
    return getAllWays(a,b,1,dp);
}

/*int check(int a,int b,int curr_num,int curr_sum){
    int res=0;
    int p = pow(curr_num,b);
    while(p+curr_sum<a){
        res += check(a,b,curr_num+1,curr_sum+p);
        curr_num++;
        p=pow(curr_num,b);
    }
    if(p+curr_sum==a)
        res++;
    return res;
}

int getAllWays(int a, int b) {
    return check(a,b,1,0);
}*/
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*brute-force
int minCount(int n){

if(sqrt(n)-floor(sqrt(n))==0)
    return 1;

    if(n<=3){
        return n;
    }

    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+minCount(n-i*i));
    }

       return ans;
}*/

//DP

int minCount(int n){

if(sqrt(n)-floor(sqrt(n))==0)
    return 1;

    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=4;i<=n;i++){

        dp[i]=i;
        for(int x=1;x*x<=i;x++){
                dp[i]=min(dp[i],1+dp[i-x*x]);
                    }

    }

     return dp[n];

}

int main(){

int n;
cout<<"Enter the value of n:" <<endl;
cin>>n;
cout<<minCount(n);
}

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

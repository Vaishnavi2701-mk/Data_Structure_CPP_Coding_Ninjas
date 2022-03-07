#include <iostream>
#include <string>
using namespace std;
#define INF 1e9
#include<cstring>
#include<limits>
int solve(string s, string v) {
    // Write your code here
    int n = s.size(), m = v.size() ,i, j, prev;
    int dp[n+1][m+1] , next[n+1][m+1];
    for(i = 0; i < n; i++){
        prev = -1;
        for(j = 0;j < m; j++){
            if(s[i] == v[j])
                prev = j;
            next[i+1][j+1] = prev;
        }
    }
    for(i = 1; i <= n; i++)
        dp[i][0] = 1;
    for(i = 0; i <= m; i++){
        dp[0][i] = INF;
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(next[i][j] == -1)
                dp[i][j] = 1;
            else{
                dp[i][j] = min(dp[i-1][j],1 + dp[i-1][next[i][j]]);
            }
        }
    }
    return dp[n][m];
}
/* brute force
#define MAX 1005
int solve(string s, string v, int m, int n){
    if(m==0){
        return MAX;
    }
    if(n==0){
        return 1;
    }
    int i;
    for(i=0;i<n;i++){
        if(s[0]==v[i]){
            break;
        }
    }
    // if not found
    if(i==n){
        return 1;
    }

 int x=solve(s+1,v,m-1,n);
 int y=solve(s+1,v+i+1,m-1;n-i-1)+1;
    return min(x,y);

int solve(string s,string v){
    int m=s.size();
    int n=v.size();

    return solve(s,v,m,n);
}*/

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}

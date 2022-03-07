#include <cstring>
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>
int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int* weight, int* value, int n, int maxWeight) {

    vector <vector<int>> dp(n+1,vector<int>(maxWeight+1));

    int i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=maxWeight;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w){
                dp[i][w]=max(value[i-1]+dp[i-1][w-weight[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][maxWeight];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}

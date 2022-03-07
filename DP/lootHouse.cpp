#include <iostream>
using namespace std;
int maxMoneyLooted(int *arr, int n)
{
	/*brute-force
       if(n<=0) return 0;

   int a= maxMoneyLooted(arr+2,n-2);
    int b=maxMoneyLooted(arr+1,n-1);

    return max(a+arr[0] , b);*/

    // dp
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);

    // dp[i] represent the maximum value stolen
    // so far after reaching house i.
    long dp[n];

    // Initialize the dp[0] and dp[1]
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    // Fill remaining positions
    for (int i = 2; i<n; i++)
        dp[i] = max(arr[i]+dp[i-2], dp[i-1]);

    return dp[n-1];
}
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}

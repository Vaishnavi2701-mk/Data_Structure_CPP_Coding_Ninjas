#include <iostream>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	    int i, j, x, y;

    // We need value+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (value = 0)
    int table[value+ 1][numDenominations];

    // Fill the enteries for 0
    // value case (value = 0)
    for (i = 0; i < numDenominations; i++)
        table[0][i] = 1;

    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < value + 1; i++)
    {
        for (j = 0; j < numDenominations; j++)
        {
            // Count of solutions including denominations[j]
            x = (i-denominations[j] >= 0) ? table[i - denominations[j]][j] : 0;

            // Count of solutions excluding denominations[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[value][numDenominations - 1];
}

/*int helper(vector<vector <int> > &dp,int c[],int n,int v){
    if(v<0)
        return 0;
    if(v==0)
        return 1;
    if(n==0)
        return 0;
    ///alredy present
    if(dp[n][v]!=0)
        return dp[n][v];

    //Either include nth coin or don't include
    int ans=helper(dp,c,n,v-c[n-1])+helper(dp,c,n-1,v);
    dp[n][v]=ans;
    return ans;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){


    vector <vector <int> > dp(numDenominations+1,vector<int>(value+1,0));
    int ans=helper(dp,denominations,numDenominations,value);

    return ans;

}
*/
int main()
{

	int numDenominations;
	cin >> numDenominations;

	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}

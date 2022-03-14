/*
Code : Edit Distance
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

#include <iostream>
#include <cstring>
using namespace std;
#include<string>
int editDistance(string s1, string s2, int **output){

  int m=s1.size();
  int n=s2.size();

    if(s1.size()==0 || s2.size()==0){
        return max(s1.size(),s2.size());
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    if(s1[0]==s2[0]){
        ans= editDistance(s1.substr(1),s2.substr(1),output);
    }
    else{
        int x=1+editDistance(s1.substr(1),s2,output);
        int y=1+editDistance(s1,s2.substr(1),output);
        int z=1+editDistance(s1.substr(1),s2.substr(1),output);

        ans=min(x,min(y,z));
    }

    output[m][n]=ans;

    return ans;


}

int editDistance(string s1, string s2)
{
  int m=s1.size();
  int n=s2.size();
  int **output=new int *[m+1];

  for(int i=0;i<=m;i++){
      output[i]=new int[n+1];
      for(int j=0;j<=n;j++){
          output[i][j]=-1;
      }
  }
    return editDistance(s1,s2,output);
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}

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

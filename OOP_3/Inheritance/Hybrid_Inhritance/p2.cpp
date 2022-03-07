#include<iostream>
#include<climits>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){

    int l[row][col];


    for(int i=0;i<row;i++)
    {
      for(int j=0;j<col;j++)
      {
        l[i][j]= INT_MAX;
      }
    }


    for(int i=0;i<col;i++)
    {
      if(arr[0][i]==0)
        l[0][i]=1;
    }
    for(int i=0;i<row;i++)
    {
      if(arr[i][0]==0)
        l[i][0]=1;
    }


    for(int i=1;i<row;i++)
    {
      for(int j=1;j<col;j++)
      {
       int p = min(min(l[i-1][j-1],l[i-1][j]),l[i][j-1]);
        if(p == INT_MAX)
        {
          if(arr[i][j]==0)
            l[i][j]=1;
          else
            l[i][j]=0;
        }
        else{
          if(arr[i][j]==0)
            l[i][j]=p+1;
          else
            l[i][j]=0;
        }
      }
    }



    int max=0;
    for(int i=0;i<row;i++)
    {
      for(int j=0;j<col;j++)
      {
        if(l[i][j]==INT_MAX)
          continue;
        if(max<l[i][j])
          max=l[i][j];
      }
    }
    return max;
  }

void find(int** arr,int** l, int i, int j,int row,int col){

    if(i>=row || j>=col)
      return ;

    int p = min(min(l[i-1][j-1],l[i-1][j]),l[i][j-1]);

    if(p!=INT_MAX)
    {

      if(arr[i][j]==0)
      {
        l[i][j]=p+1;
      }
      else{
        l[i][j]=0;
      }
    }
    else{
      if(arr[i][j]==0)
      {
        l[i][j]=1;
      }
      else{
        l[i][j]=0;
      }

    }

      if(i <row && j+1 <col && l[i][j+1]==INT_MAX)
        find(arr,l,i,j+1,row,col);
      if(i+1 <row && j <col && l[i+1][j]==INT_MAX)
        find(arr,l,i+1,j,row,col);
      if(i+1 <row && j+1 <col && l[i+1][j+1]==INT_MAX)
        find(arr,l,i+1,j+1,row,col);
  }

int main(){
    int n,m;
    cin>>n>>m;

int **arr= new int *[n];
for(int i=0;i<n;i++){
    arr[i]=new int[m];
    for(int j=0;j<m;j++){
        cin>> arr[n][m];
    }
}


}

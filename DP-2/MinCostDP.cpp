#include <iostream>
using namespace std;
#include<cmath>
#include<climits>

int minCost_DP(int **input,int m,int n){

int **output=new int *[m];
for(int i=0;i<m;i++){
    output[i]=new int [n];
}

// fill the independent i.e. destination cell

output[m-1][n-1]=input[m-1][n-1];

// Fill the last row from right to left

for(int j=n-2;j>=0;j--){
    output[m-1][j]=output[m-1][j+1]+input[m-1][j];
}

// Fill the last column from bottom to up

for(int i=m-2;i>=0;i--){
    output[i][n-1]=output[i+1][n-1]+input[i][n-1];
}

// Fill the remaining cells

for(int i=m-2;i>=0;i--){
for(int j=n-2;j>=0;j--){
    output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
}
}

return output[0][0];

}

int main(){
int m,n ;
cout<<"Enter the value of rows and column: "<<endl;
cin>>m>>n;

int **input=new int *[m];
for(int i=0;i<m;i++){
    input[i]=new int [n];
    for(int j=0;j<n;j++){
        cin>>input[i][j];
    }
}
cout<<minCost_DP(input,m,n)<<endl;
}


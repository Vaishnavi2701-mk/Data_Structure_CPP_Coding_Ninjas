#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MinCost(int **arr,int m,int n,int i, int j,int**output){

//base case
if(i==m-1 && j==n-1){
    return arr[i][j];
}
//if out of the range
if(i>=m || j>=n){
    return INT_MAX;
}
//check if answer already exist
if(output[i][j]!=-1){
    return output[i][j];
}

//recursive call
int x=MinCost(arr,m,n,i,j+1,output);
int y=MinCost(arr,m,n,i+1,j+1,output);
int z=MinCost(arr,m,n,i+1,j,output);

//small calculation

int a=min(x,min(y,z))+arr[i][j];

//save the answer for future use

output[i][j]=a;

return a;


}



int MinCost(int **arr,int m,int n){

int **output=new int *[m];
for(int i=0;i<m;i++){
    output[i]=new int [n];
    for(int j=0;j<n;j++){
        output[i][j]=-1;
    }
}
return MinCost(arr,m,n,0,0,output);

}

int main(){
int m,n;
cout<<"Enter the values of rows and column: "<<endl;
cin>>m>>n;

int **arr=new int*[m];
for(int i=0;i<m;i++){
    arr[i]=new int [n];
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
cout<<MinCost(arr,m,n)<<endl;

}

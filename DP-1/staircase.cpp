#include<iostream>
using namespace std;

/*Brute force

int Staircase(int n){
if(n==0){
    return 0;
}
if(n==1){
    return 1;

}
if(n==2){
    return 2;
}
if(n==3){
    return 4;
}

return Staircase(n-1)+Staircase(n-2)+Staircase(n-3);

}*/

//DP

long staircase(int n){

long ans[n+1];
ans[0]=0;
ans[1]=1;
ans[2]=2;
ans[3]=4;

for(int i=4;i<=n;i++){
    ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
}
return ans[n];
}
int main(){

int n;
cin>>n;
cout<<staircase(n);

}

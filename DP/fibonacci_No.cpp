#include<iostream>
using namespace std;

/*Brute-force approach
int fibo_1(int n){

//base case
if(n<=1){
    return n;
}

int a=fibo_1(n-1);
int b=fibo_1(n-2);

return a+b;



}*/

/*Memonization(Top-down approach)
int fibo_2_helper(int n,int *ans){
if(n<=1){
    return n;
}
//check if output is already present st the ans[n] if yes then simply return
if(ans[n]!=-1){
    return ans[n];
}
//if No then call recursion
int a=fibo_2_helper(n-1,ans);
int b=fibo_2_helper(n-2,ans);

//save the output first
ans[n]=a+b;

// return the output

return ans[n];

}
int fibo_2(int n){

int *ans=new int [n+1];
for(int i=0;i<=n;i++){
    ans[i]=-1;
}
return fibo_2_helper(n,ans);

}*/

//Dynamic programming (bottom-down approach)

int fibo_3(int n){

int *ans=new int [n+1];
ans[0]=0;
ans[1]=1;

for(int i=2;i<=n;i++){
    ans[i]=ans[i-1]+ans[i-2];
}
return ans[n];
}


int main(){

int n;
cout<<"Enter the value f n: "<<endl;
cin>>n;
cout<<fibo_3(n)<<endl;

}

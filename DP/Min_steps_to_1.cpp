#include<iostream>
#include<cmath>
using namespace std;

/*brute-force
int countMinStepsTo1(int n){
if(n==1){
    return 0;
}

int a=INT_MAX,b=a,c=b;
a=countMinStepsTo1(n-1);
if(n%2==0){
    b=countMinStepsTo1(n/2);
}
if(n%3==0){
    c=countMinStepsTo1(n/3);
}

return 1+min(a,min(b,c));

}*/

/*Memonization

int countMinStepsTo1_helper(int n,int *ans){
if(n<=1){
    return 0;
}
if(ans[n]!=-1){
    return ans[n];
}
int a=countMinStepsTo1_helper(n-1,ans);
int b=a,c=b;
if(n%2==0){
    b=countMinStepsTo1_helper(n/2,ans);
}
if(n%3==0){
    c=countMinStepsTo1_helper(n/3,ans);
}
int output=min(a,min(b,c))+1;
ans[n]=output;

return output;

}
int countMinStepsTo1(int n){
int *ans=new int[n+1];

for(int i=0;i<=n;i++){
    ans[i]=-1;
}
return countMinStepsTo1_helper(n,ans);
}*/

//DP
int countMinStepsTo1(int n){

		  int a[n+1];

    a[1]=0; a[2]=a[3]=1;
   int b,c;
    for(int i=4 ;i<n+1;i++)
    {
        b=c=n;

       if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];

      a[i]=1+ min(a[i-1] ,min(b,c));
    }
return a[n];
}

int main(){

int n;
cout<<"Enter the value of n:" <<endl;
cin>>n;
cout<<countMinStepsTo1(n);
}

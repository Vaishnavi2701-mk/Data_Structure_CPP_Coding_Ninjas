/*
Code : Min Steps to 1

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 200

Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  */

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

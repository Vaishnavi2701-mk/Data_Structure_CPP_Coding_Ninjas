#include<iostream>
using namespace std;

int power(int x,int n){
if(n==0){
return 1;
}
int count=0,m=1;
while(count<n){
    m=m*x;
    count++;
}
return m;
int ans=power(x,n-1);
return x*ans;
}
int main(){
int x,n;
cin>>x>>n;
int output=power(x,n);
cout<<output<<endl;
}

#include<iostream>
using namespace std;
int lastIndex(int a[], int n, int x) {

if(n==0){
    return -1;
}
if(a[n-1]==x){
    return n-1;
}
int ans=lastIndex(a,n-1,x);
if(ans==-1){
    return -1;
}
else{
    return ans;
}
}

int main(){
int a[5]={3,5,2,7,2};
int x;
cout<<"Enter the integer:"<<endl;
cin>>x;
cout<<lastIndex(a,5,x)<<endl;
}


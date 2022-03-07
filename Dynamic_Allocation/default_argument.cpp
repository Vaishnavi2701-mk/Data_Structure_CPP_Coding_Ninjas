#include<iostream>
using namespace std;


int sum(int a[],int n,int si=0){
int ans=0;
for(int i=si;i<n;i++){
    ans+=a[i];
}
return ans;
}
int sum2(int a,int b, int c=0,int d=0){
return a+b+c+d;
}
int main(){
int a[20];
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
//cout<<sum(a,n,2)<<endl; // here staring index is 2 so sum will start from second index;
//  but what if I didn' pass si; it will give me error ,so that why we declare si as 0 means even if I am not passing anything it will use 0 instead of that;
cout<<sum(a,n)<<endl;
int p=2,q=5;
cout<<sum2(p,q)<<endl;

}

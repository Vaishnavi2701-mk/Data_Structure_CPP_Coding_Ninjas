#include<iostream>
using namespace std;

int multiplication(int m, int n){
if(m==0||n==0){
    return 0;
}
int ans=m+multiplication(m,n-1);
return ans;

}


int main(){
int m,n;
cout<<"Enter the integers: "<<endl;
cin>>m>>n;
cout<<"Ans: "<<multiplication(m,n)<<endl;
}

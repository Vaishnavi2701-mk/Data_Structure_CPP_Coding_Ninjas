#include<iostream>
using namespace std;

bool helperFunction(char a[],int start,int end){
if(start>=end){
    return true;
}
if(a[start]!=a[end]){
    return false;
}
return helperFunction(a,start+1,end-1);

}

bool checkPalindrome(char a[]){
int len=0;
for(int i=0;a[i]!='\0';i++){
    len++;
}
return helperFunction(a,0,len-1);
}

int main(){
char a[50];
cout<<"Enter the string: "<<endl;
cin>>a;
cout<<a<<endl;
cout<<"Ans: "<<checkPalindrome(a)<<endl;
}

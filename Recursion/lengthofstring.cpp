#include<iostream>
using namespace std;

void removeX(char a[]){
if(a[0]=='\0'){
    return;
}
if(a[0]!='x'){
    removeX(a+1);
}
else{
    int i=1;
    for(;a[i]!='\0';i++){
        a[i-1]=a[i];
    }
     a[i-1]='\0';
     removeX(a);   //here for eg;xxafgf after shifting , it will be xafgf so it is my new string thats why only passed a;
    }

}

int length(char a[]){
if(a[0]=='\0'){
    return 0;
}
int smallstringlength=length(a+1);
return smallstringlength+1;
}
int main(){

char a[100];
cin>>a;
cout<<length(a)<<endl;
removeX(a);
cout<<a<<endl;
int l=length(a); // after the changes find out the length;
cout<<l<<endl;
}

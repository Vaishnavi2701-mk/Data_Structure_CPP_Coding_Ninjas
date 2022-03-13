#include<iostream>
using namespace std;

/*bool isSorted(int a[],int n){
if(n==0||n==1){
    return true;
}
if(a[0]>a[1]){
    return false;
}
bool isSmallerOutput=isSorted(a+1,n-1);
return isSmallerOutput;

}*/
bool isSorted(int a[],int n){
if(n==0||n==1){
    return true;
}
bool isSmallerOutput=isSorted(a+1,n-1);    // here first it jump out to next element
if(a[0]>a[1]){                             // then it is checking that first two elements are sorted or not
    return false;
}
if(!isSmallerOutput){                     // then we should have to check that while array is sorted or not
    return false;
}
else{
    return true;
}
}


int main(){
int a[10]={1,2,3,4,5,6,7,8,9,10};
cout<<"Ans: "<<isSorted(a,10)<<endl;
}

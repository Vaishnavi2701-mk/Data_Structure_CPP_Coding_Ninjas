#include<iostream>
using namespace std;

//int sum(int a[],int n)
int sum(int *a, int n){
int sum=0;
for(int i=0;i<n;i++){
    //sum+=a[i];
    sum+=*(a+i);
}
return sum;
}



int main(){

int a[10]={1,2,3,4,5,6,7,8,9,10};
//cout<<sum(a,10);   basically we are passing pointer
cout<<sum(a+3,7);    // we could pass the part of array; like here I am passing array from third element so from starting to third element it will make a sum up-to the end;

                     // starting from 3 that means size is 7 now;

}

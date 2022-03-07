#include<iostream>
using namespace std;

bool isMaxheap(int arr[],int n){

for(int i=0;i<=(n-2)/2;i++){
    if(arr[2*i+1]>arr[i]){    // if we are entering inside that means it definitely have one child and that would be left child because of CBT
        return false;
    }
    if((2*i+2)<n&&arr[2*i+2]>arr[i]){  // we are not sure that it have second child as well so check it first that right child is present or not..
        return false;
    }
}
return true;

}

int main(){

int arr[]={4,20,18,6,14,11,9,4};

cout<<(isMaxheap(arr,8)?"true\n":"false\n")<<endl;

}

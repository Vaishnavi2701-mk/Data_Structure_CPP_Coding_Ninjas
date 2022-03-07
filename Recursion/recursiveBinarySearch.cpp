#include<iostream>
using namespace std;
int helperFunction(int input[],int s,int e,int x){

if(e>=s){
    int mid=(s+e)/2;
    if(input[mid]==x){
        return mid;
    }
    if(input[mid]>x){
        return helperFunction(input,s,mid-1,x);
    }
    if(input[mid]<x){
        return helperFunction(input,mid+1,e,x);
    }
}
return -1;


}

int binarySearch(int input[],int length,int element){

    return helperFunction(input,0,length-1,element);

}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    {
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

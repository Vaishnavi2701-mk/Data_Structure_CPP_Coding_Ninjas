#include<iostream>
using namespace std;

void helperFunction(int input[],int n,int output[],int i,int j){
if(i==n){
    int k=0;
    while(k<j){
        cout<<output[k]<<' ';
        k++;
    }
    cout<<endl;
    return;
}
helperFunction(input,n,output,i+1,j);
output[j]=input[i];
helperFunction(input,n,output,i+1,j+1);

}


void printSubsetsOfArray(int input[],int size){
int output[10000];
helperFunction(input,size,output,0,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

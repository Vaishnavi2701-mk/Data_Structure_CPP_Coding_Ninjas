#include<iostream>
using namespace std;

void helperFunction(int input[],int k,int n,int i,string output){

if(n==0){
    if(k==0){
        cout<<output<<endl;
    }
}
else{
    return;
}
helperFunction(input,k,n,i+1,output);
helperFunction(input,k-input[i],n,i+1,output+" "+input[i]);
               }

void printSubsetSumToK(int input[],int size,int k){

string output="";
helperFunction(input,k,size,0,output);

}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}


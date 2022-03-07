#include<iostream>
using namespace std;

void helperFunction(string input,int s,int e){
if(s==e){
    cout<<input<<endl;
}
int i=s;
for(;i<=e;i++){
    swap(input[s],input[i]);
    helperFunction(input,s+1,e);
    swap(input[s],input[i]);
}

}

void printPermutations(string input){
int length=input.length();
helperFunction(input,0,length-1);

}
int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}

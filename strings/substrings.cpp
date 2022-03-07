#include<iostream>
#include<math.h>
using namespace std;
int subs(string input,string output[]){
if(input.empty())/*input.size()==0*/{
    output[0]=" ";
    return 1;
}
string substring=input.substr(1);
//int subStrSize=subs(input+1,output);  it will error because input is string not an array and 1 is int; string and int addition nahi hoti;
int subStrSize=subs(substring,output);
for(int i=0;i<subStrSize;i++){
    output[i+subStrSize]=input[0]+output[i];
}
return 2*subStrSize;

}
int main(){

string input;
cin>>input;
int size=input.size();
int arraySize=pow(2,size);
//string *output=new string[10000];
string *output=new string[arraySize];
int count=subs(input,output);
for(int i=0;i<count;i++){
    cout<<output[i]<<endl;
}

}

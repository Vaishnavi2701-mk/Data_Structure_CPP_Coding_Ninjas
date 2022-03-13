#include<iostream>
using namespace std;

int forInt(char a){
int i=a-'0';
return i;

}
char forChar(int i){
char c='a'+i-1;
return c;
}
int getCodes(string input,string output[10000]){
if(input.length()==0){
    output[0]="";
    return 1;
}
if(input.length()==1){
    output[0]=forInt(forChar(input[0]));
    return 1;
}
string output1[10000];
string output2[10000];
int sizeOfoutput2=0;
int sizeOfoutput1=getCodes(input.substr(1),output1);
if(input.length()>1){
    if(forInt(input[0])*10+forInt(input[1])>10&&forInt(input[0])*10+forInt(input[1])<27){
        sizeOfoutput2=getCodes(input.substr(2),output2);
    }
}
for(int i=0;i<sizeOfoutput1;i++){
    output[i]=forChar(forInt(input[0]))+output1[i];
}
for(int i=0;i<sizeOfoutput2;i++){
    output[i+sizeOfoutput1]=forChar(forInt(input[0]))+output2[i];
}
return sizeOfoutput1+sizeOfoutput2;
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

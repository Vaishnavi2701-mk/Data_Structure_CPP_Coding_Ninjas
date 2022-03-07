#include<iostream>
using namespace std;

string mapping(int n){
if(n==2){
    return "abc";
}
if(n==3){
    return "def";
}
if(n==4){
    return "ghi";
}
if(n==5){
    return "jkl";
}
if(n==6){
    return "mno";
}
if(n==7){
    return "pqrs";
}
if(n==8){
    return "tuv";
}
if(n==9){
    return "wxyz";
}
return " ";
}
void finalPrint(int num,string output){
if(num==0){
    cout<<output<<endl;
    return;
}
string lastdigit=mapping(num%10);
for(int i=0;i<lastdigit.length();i++){
    finalPrint(num/10,lastdigit[i]+output);
}
}


void keypad(int num){
finalPrint(num,"");
}
int main(){
int num;
cin>>num;
keypad(num);

}

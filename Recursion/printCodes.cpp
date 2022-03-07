#include<iostream>
#include<cstring>
using namespace std;

int atoi(char a){
int i=a-'0';
return i;
}
char itoa(int i){

char c='a'+i-1;
return c;
}

void helperFunction(string input,string output){
if(input.empty()){
    cout<<output<<endl;
    return;

}
int ch1=atoi(input[0]);

helperFunction(input.substr(1),output+(itoa(ch1)));
 if(input.length()>=2){
    int ch2=atoi(input[0]);
    int ch3=atoi(input[1]);
    int x=ch2*10+ch3;
    if(x>=10&&x<=26){
        int ch4=x;
        helperFunction(input.substr(2),output+(itoa(ch4)));
    }
 }


}
void printAllPossibleCodes(string input){
string output="";
helperFunction(input,output);
}
int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

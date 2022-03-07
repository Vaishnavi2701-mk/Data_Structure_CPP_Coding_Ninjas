#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string uniqueCharacter(string str){

int len=str.length();
if(len==0){
    char *ans=new char[1];
    ans[0]='\0';
    return ans;

}

char * ans=new char[len+1];
unordered_map <char , bool> hm;

int i=0;

for(int currentIndex=0;currentIndex<len;currentIndex++){

    char currentCharacter=str[currentIndex];
    if(hm.count(currentCharacter)==0){
        hm[currentCharacter]=true;
        ans[i]=currentCharacter;
        i++;
    }

}

ans[i]='\0';
return ans;

}

int main(){

string str;
cout<<"Enter the string: "<<endl;
cin>>str;

cout<<uniqueCharacter(str)<<endl;

}

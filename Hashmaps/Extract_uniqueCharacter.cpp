/*
Extract Unique characters

Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/
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

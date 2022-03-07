#include<iostream>
using namespace std;


int main(){

string s="abc";
string s1;
s1="def";
s1="porhu";// we can directly update strings;
cout<<s<<endl;
cout<<s1<<endl;

string * s2=new string;
*s2="def";
cout<<s2<<endl;
cout<<*s2<<endl; // we could also create a string dynamically;

string s3="abcd";
cout<<s3<<endl;
//cin>>s3;it will stop at null so we cant take input in  this;
getline(cin,s3);
cout<<s3<<endl;

s="ghggduh";//string hai tho we are taking in double quotes
cout<<s[0]<<endl;
s[0]='f';// but at a particular index it is in single quotes
s[4]='g';
cout<<s<<endl;

string sf=s+s3;
cout<<sf<<endl;// we could add two strings;
s+=s3;
cout<<s<<endl;

cout<<s.size()<<endl;// we could directly find out size of string;
cout<<s.substr(3)<<endl;// from 3 to onwards
cout<<s.substr(3,5)<<endl;// from 3 to next 5 elements;

cout<<s.find("gg")<<endl;// it will find out if that substring is present then it will give me index at which it is present;
}

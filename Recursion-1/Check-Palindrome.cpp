/* Check-Palindrome

Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/
#include<iostream>
using namespace std;

bool helperFunction(char a[],int start,int end){
if(start>=end){
    return true;
}
if(a[start]!=a[end]){
    return false;
}
return helperFunction(a,start+1,end-1);

}

bool checkPalindrome(char a[]){
int len=0;
for(int i=0;a[i]!='\0';i++){
    len++;
}
return helperFunction(a,0,len-1);
}

int main(){
char a[50];
cout<<"Enter the string: "<<endl;
cin>>a;
cout<<a<<endl;
cout<<"Ans: "<<checkPalindrome(a)<<endl;
}

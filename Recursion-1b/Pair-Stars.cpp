/*
Pair Star

Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
void pairStars(char a[]){
int len=strlen(a);
if(a[0]=='\0'||a[1]=='\0'){
    return ;
}
if(a[0]==a[1]){
    int i=len;
    for(;i>=1;i--){
        a[i+1]==a[i];
    }
    a[1]='*';
return pairStars(a+2);
}
return pairStars(a+1);
}
int main() {
   char a[100];
   cin.getline(a, 100);
   pairStars(a);
   cout << a << endl;
}

/* 
String-To-Integer

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567

*/

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

int stringToInteger(char a[]){
  int len=strlen(a);
 if(len==1){
    return a[0]-48;
  }
  int ans=stringToInteger(a+1);
  int b=a[0]-48;
 return b*(int)pow(10,len-1)+ans;

}
int main() {
    char a[50];
    cin >> a;
    cout << stringToInteger(a) << endl;
}

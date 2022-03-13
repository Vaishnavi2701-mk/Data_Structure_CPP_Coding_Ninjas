/* Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :

Integer n

Output Format :

All possible strings in different lines

Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
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


void printKeypad(int num){
finalPrint(num,"");
}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}


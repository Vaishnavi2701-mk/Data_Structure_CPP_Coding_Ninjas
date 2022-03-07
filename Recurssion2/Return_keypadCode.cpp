/* Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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
int keypad(int num, string output[]){

if(num==0){
    output[0]="";
    return 1;
}
int smallerOutputSize=keypad(num/10,output);
string lastdigit=mapping(num%10);
string temp[10000];
int k=0;
    for(int j=0;j<lastdigit.size();j++){
        for(int i=0;i<smallerOutputSize;i++){
        temp[k]=output[i]+lastdigit[j];
        k++;
    }
}
for(int i=0;i<k;i++){
    output[i]=temp[i];
}
return smallerOutputSize*lastdigit.size();

}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

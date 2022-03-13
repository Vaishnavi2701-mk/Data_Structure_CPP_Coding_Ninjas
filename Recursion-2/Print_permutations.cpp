/* Print Permutations

Given an input string (STR), print all possible permutations of the input string.
Note:

The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:

The only input line contains a string (STR) of alphabets in lower case

Output Format:

Print each permutations in a new line

Note:

You do not need to print anything, it has already been taken care of. Just implement the function.

Constraint:

1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:

cba

Sample Output 1:

abc
acb
bac
bca
cab
cba

*/
#include <iostream>
#include <string>
using namespace std;

void swap(char *a,char *b){
   char temp=*a;
    *a=*b;
    *b=temp;

}
void helperFunction(string input,int s,int e){
if(s==e){
    cout<<input<<endl;
}
int i=s;
for(;i<=e;i++){
    swap(input[s],input[i]);
    helperFunction(input,s+1,e);
    swap(input[s],input[i]);
}

}

void printPermutations(string input){
int length=input.length();
helperFunction(input,0,length-1);

}
int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}

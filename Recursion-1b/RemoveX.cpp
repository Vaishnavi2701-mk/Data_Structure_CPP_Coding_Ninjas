/* 
Remove X
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/
#include<iostream>
using namespace std;

void removeX(char a[]) {
    // Write your code here
    if(a[0]=='\0'){
    return;
}
removeX(a+1);
if(a[0]=='x'){
        int i=1;
    for(;a[i]!='\0';i++){
        a[i-1]=a[i];
    }
    a[i-1]='\0';
}
else{
    return;
}

}

int main() {
    char a[100];
    cin.getline(a, 100);
    removeX(a);
    cout << a << endl;
}

/* Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :

String S

Output Format :

Output string

Constraints :

1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :

aabccba

Sample Output 1 :

abcba

Sample Input 2 :

xxxyyyzwwzzz

Sample Output 2 :

xyzwz

*/
#include <iostream>
using namespace std;
void removeConsecutiveDuplicates(char *s) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

if(s[0]=='\0'){
    return;
}
if(s[0]!=s[1]){
    removeConsecutiveDuplicates(s+1);
}
else{
    int i=1;
    for(;s[i]!='\0';i++){
        s[i-1]=s[i];
    }
    s[i-1]='\0';
    removeConsecutiveDuplicates(s);
}
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}

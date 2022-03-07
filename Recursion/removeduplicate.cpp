#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char s[]){
if(s[0]=='\0'){
    return;
}
/* Method 1(first make a recurssive call;)
removeConsecutiveDuplicates(s+1);
if(s[0]==s[1]){
    int i=1;
    for(;s[i]!='\0';i++){
        s[i-1]=s[i];
    }
    s[i-1]='\0';
}
else{
    return;
}*/

// Method 2
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

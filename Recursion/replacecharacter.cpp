#include<iostream>
using namespace std;

void replaceCharacter(char input[],char c1, char c2){
if(input[0]=='\0'){
    return;
}
/*Method 1
if(input[0]!=c1){
    replaceCharacter(input+1,c1,c2);
}
else{

    input[0]=c2;
    replaceCharacter(input,c1,c2);
}*/
//Method 2;
replaceCharacter(input+1,c1,c2);
if(input[0]==c1){
    input[0]=c2;
}
else{
    return;
}
}
int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

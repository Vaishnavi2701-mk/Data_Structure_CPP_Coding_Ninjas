/*
Replace Pi(Recursive)

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
*/#include<iostream>
using namespace std;

void replacePi(char a[]){
int len=0;
for(int i=0;a[i]!='\0';i++){
    len++;
}
 if(a[0]=='\0'){
    return;
 }
replacePi(a+1);
if(a[0]=='p'&&a[1]=='i'){
        int i=a[len-1];
    for(;i>=2;i--){
        a[i+2]=a[i];
    }
    a[0]='3';
    a[1]='.';
    a[2]='1';
    a[3]='4';

}
else{
    return;
}


}
int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

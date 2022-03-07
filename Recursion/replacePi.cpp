#include<iostream>
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

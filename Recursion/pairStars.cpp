#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
void pairStars(char a[]){
int len=strlen(a);
if(a[0]=='\0'||a[1]=='\0'){
    return ;
}
if(a[0]==a[1]){
    int i=len;
    for(;i>=1;i--){
        a[i+1]==a[i];
    }
    a[1]='*';
return pairStars(a+2);
}
return pairStars(a+1);
}
int main() {
   char a[100];
   cin.getline(a, 100);
   pairStars(a);
   cout << a << endl;
}

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

int stringToInteger(char a[]){
  int len=strlen(a);
 if(len==1){
    return a[0]-48;
  }
  int ans=stringToInteger(a+1);
  int b=a[0]-48;
 return b*(int)pow(10,len-1)+ans;

}
int main() {
    char a[50];
    cin >> a;
    cout << stringToInteger(a) << endl;
}

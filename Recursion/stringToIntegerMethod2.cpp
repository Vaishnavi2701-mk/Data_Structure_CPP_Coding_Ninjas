#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

int helperFunction(char a[],int len){
 if(len==1){
    return a[0]-48;
  }
  int ans=helperFunction(a,len-1);
  int b=a[len-1]-48;
 return ans*10+b;

}

int stringToInteger(char a[]){
  int len=strlen(a);
return helperFunction(a,len);

}
int main() {
    char a[50];
    cin >> a;
    cout << stringToInteger(a) << endl;
}

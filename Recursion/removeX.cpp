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

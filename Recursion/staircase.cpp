#include<iostream>
using namespace std;

int staircase(int n){
if(n==0 || n==1){
    return 1;
}

else{
    return staircase(n-3)+staircase(n-2)+staircase(n-1);
}

}


int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}


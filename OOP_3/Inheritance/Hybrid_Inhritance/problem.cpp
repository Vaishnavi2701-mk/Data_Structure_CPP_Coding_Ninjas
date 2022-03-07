#include<iostream>
using namespace std;

void printPatt(int n){



    int n1=(n/2);

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n1-i;j++)
            cout<<'*';
        for(int l=1;l<=2*i-1;l++)
            cout<<' ';
        for(int k=1;k<=n1-i+1;k++)
            cout<<'*';
        cout<<endl;
    }

       for(int i=n1-i;i>=1;i--){
        for(int j=1;j<=n1-i+1;j++)
            cout<<'*';
        for(int l=1;l=2*i-1;l++)
            cout<<' ';
        for(int k=1;k<=n1-i+1;k++)
            cout<<'*';

        cout<<endl;
    }


}

int main(){
    int n;
    cin>>n;
printPatt(n);
return 0;
}

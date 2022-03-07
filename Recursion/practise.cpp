#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

void towerofHanoi(int n,char source,char auxillery, char destination){

if(n==1){
    cout<<source<<" "<<destination<<endl;
}
if(n==0){
    return;
}
towerofHanoi(n-1,source,destination,auxillery);
cout<<source<<" "<<destination<<endl;
towerofHanoi(n-1,auxillery,source,destination);


}
int main(){
int n;
cin>>n;
towerofHanoi(n,'a','b','c');

}

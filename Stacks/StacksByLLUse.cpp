#include<iostream>
using namespace std;
#include "StacksByLL.cpp"

int main(){

Stack s;

int t;
cin>>t;           // no of operations we have to perform

while(t--){
    int choice,input;
    cin>>choice;
    switch(choice){
    case 1:
        cin>>input;
        s.push(input);
        break;
    case 2:
        cout<<s.pop()<<endl;
        break;
    case 3:
        cout<<s.top()<<endl;
        break;
    case 4:
        cout<<s.getSize()<<endl;
        break;
    default:
        cout<<(s.isEmpty()?"true\n":"false\n")<<endl;




    }




}

}

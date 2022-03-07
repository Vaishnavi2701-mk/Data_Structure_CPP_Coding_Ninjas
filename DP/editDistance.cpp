#include<string>
#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2) {
//base case
    if(s1.size()==0 || s2.size()==0){
        return max(s1.size(),s2.size());
    }
    if(s1[0]==s2[0]){
        int w= editDistance(s1.substr(1),s2.substr(1));
        return w;
    }
    else{
        int x=1+editDistance(s1.substr(1),s2);
        int y=1+editDistance(s1,s2.substr(1));
        int z=1+editDistance(s1.substr(1),s2.substr(1));

        return min(x,min(y,z));
    }
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}

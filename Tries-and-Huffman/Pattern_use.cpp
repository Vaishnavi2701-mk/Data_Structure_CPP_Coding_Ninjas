#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"pattern_matching.h"

int main() {
    pattern_matching t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternSearch(vect, pattern) ? "true" : "false");
}

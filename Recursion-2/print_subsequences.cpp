#include <iostream>
using namespace std;

void printSubsequences(string input, string output)
{
    // base case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    printSubsequences(input.substr(1), output + input[0]);
    printSubsequences(input.substr(1), output);
}

int main()
{
    string input;
    cin >> input;
    string output = " ";
    printSubsequences(input, output);
    return 0;
}
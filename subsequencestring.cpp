
#include <iostream>
using namespace std;

int substring(string input, string output[])
{
    if (input.empty())
    {
        output[0] = ' ';
        return 1;
    }
    int size = substring(input.substr(1), output);
    for (int i = 0; i < size; i++)
    {
        output[i + size] = input[0] + output[i];
    }
    return 2 * size;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int size = substring(input, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
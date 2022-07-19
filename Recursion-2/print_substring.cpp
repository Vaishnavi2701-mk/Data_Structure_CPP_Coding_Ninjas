
#include <iostream>
#include <cstring>
using namespace std;

void print_substring(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        for (int j = 0; a[j] != '\0'; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k];
            }
            cout << endl;
        }
    }
}

int main()
{
    char input[1000000];
    cin >> input;
    print_substring(input);
}

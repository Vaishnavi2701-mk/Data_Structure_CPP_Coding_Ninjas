/* Print Subset Sum to K

Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :

Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Sample Input:

9
5 12 3 17 1 18 15 3 17
6

Sample Output:

3 3
5 1

*/
#include <iostream>
using namespace std;
void helperFunction(int input[],int k,int n,int output[], int m){

	// 1st base case, when you get a subset sum:
    if(k == 0) {
        for(int i = 0; i < m; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }

    //2nd base case, when n becomes zero but you don't get the subset sum:
    if(n == 0)
        return;

    // Case 1: when we don't consider the current element:
    helperFunction(input+1,k,n-1,output, m);

    // Case 2: when we consider the current element
    int new_output[m+1];
    for(int i = 0; i < m; i++)
        new_output[i] = output[i];
    new_output[m] = input[0];
    helperFunction(input+1,k-input[0],n-1,new_output, m+1);
}

void printSubsetSumToK(int input[],int size,int k){

int output[10000];
helperFunction(input,k,size,output,0);

}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}


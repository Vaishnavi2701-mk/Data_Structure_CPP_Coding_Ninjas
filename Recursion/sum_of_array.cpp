/* Sum of Array
Send Feedback
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :

Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :

Sum

Constraints :

1 <= N <= 10^3

Sample Input 1 :

3
9 8 9

Sample Output 1 :

26

Sample Input 2 :

3
4 2 1

Sample Output 2 :

7

*/
#include<iostream>
using namespace std;
int sum(int a[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
if(n==0){
    return 0;
}
if(n==1){
    return a[0];
}
int sumOfArray=a[0]+a[1];
int nextSum=sum(a+2,n-2);
return sumOfArray+nextSum;
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << sum(input, n) << endl;
}


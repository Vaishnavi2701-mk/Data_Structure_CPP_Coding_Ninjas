/*
Longest subset zero sum

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
*/

#include <iostream>
using namespace std;
#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,int> freq;
    for(int i=1;i<n;i++) {
        arr[i]+=arr[i-1];
    }
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            if(m<i+1){
                m=i+1;
            }
        }
        else if(freq.count(arr[i])>0){
            if(m<i-freq[arr[i]]){
                m=i-freq[arr[i]];
            }
        }
        else{
            freq[arr[i]]=i;
        }
    }
    return m;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}





































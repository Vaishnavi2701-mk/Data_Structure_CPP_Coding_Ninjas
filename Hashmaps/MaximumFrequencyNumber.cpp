/*
Code : Maximum Frequency Number

You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1*/
#include <iostream>
using namespace std;
#include<unordered_map>
int highestFrequency(int arr[], int n) {
unordered_map<int,int> map;// we are getting key as an integer from array and value we will store it will be integer as well

    for(int i=0;i<n;i++){
        int key=arr[i];
        if(map.count(key)==0){
            map[key]=1;   // if key will occures one time then initiallize its value by 1;
        }
        else{
            map[key]++;  // if key occures more than one time then only update value;
        }
    }

    int maximum=map[arr[0]];   // consider 0th element have maximum occurence
    int element=arr[0];        // it will be 0th element

    int j=1;
    while(j<n){
        if(map[arr[j]]>maximum){   //if the next element of array will have greater value that previous one then update
            maximum=map[arr[j]];
            element=arr[j];
        }
        j++;
    }
    return element;

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}

/*
Running Median

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/#include<iostream>
#include<queue>
using namespace std;

void runningMedian(int arr[],int n){
// if array is empty

if(n==0){
    return;
}

// make min-heap and max-heap

priority_queue<int> max;
priority_queue<int,vector<int>,greater<int>>min;

int med=arr[0];
max.push(arr[0]);
cout<<med<<" ";

for(int i=1;i<n;i++){

    int x=arr[i];

    //case 1: when max heap is greater in size
    if(max.size()>min.size()){
        if(x<med){
            min.push(max.top());
            max.pop();
            max.push(x);
        }
        else{
            min.push(x);
        }
        med=(max.top()+min.top())/2.0;
    }

    //case 2: when both are equal in size
    else if(max.size()==min.size()){
        if(x<med){
            max.push(x);
            med=(int)max.top();
        }
        else{
            min.push(x);
            med=(int)min.top();
        }

    }

    //case 3: when min heap is greater in size
    else{


        if(x>med){

            max.push(min.top());
            min.pop();
            min.push(x);

        }
        else{
            max.push(x);
        }

        med=(max.top()+min.top())/2.0;

    }
     cout<<med<<" ";

}
}
int main(){

int arr[]={7,2,8,3,1,5};

cout<<"Running median: "<<endl;
runningMedian(arr,6);


}

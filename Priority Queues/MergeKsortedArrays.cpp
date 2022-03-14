/*
Merge K sorted arrays

Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.
Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.
Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> mergeKsortedArrays(vector<vector<int>*>input){

//output vector for final result

vector<int> output;
priority_queue<int,vector<int>,greater<int>>pq;

for(int i=0;i<input.size();i++){
    //store each array present in input vector in new vector
    vector<int>*q=input[i];
    //store each element of vector q in pq;

    for(int j=0;j<q->size();j++){
        pq.push(q->at(j));
    }
}

// now pq contain all the elements af all k arrays;
//we will push it in output vector ,as it is built-in min priority queueit will push minimum element first and everything goes on like this

while(!pq.empty()){
    output.push_back(pq.top());
    pq.pop();
}
return output;


}

int main(){

int k;
cout<<"Enter the number of arrays: "<<endl;
cin>>k;

vector<vector<int>*>input;

for(int j=1;j<=k;j++){
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;

    vector<int>*current=new vector<int>;

    for(int i=0;i<size;i++){
        int a;
        cin>>a;
        current->push_back(a);
    }
    input.push_back(current);
}

vector<int>output=mergeKsortedArrays(input);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}

}

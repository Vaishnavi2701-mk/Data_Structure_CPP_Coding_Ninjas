/*
Code : K smallest Elements

You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> kSmallest(int arr[],int n,int k){

priority_queue<int> min;

// we are using built in max; so everything act according to that

for(int i=0;i<k;i++){
    min.push(arr[i]);
}

for(int i=k;i<n;i++){
    if(min.top()>arr[i]){
        min.push(arr[i]);
        min.pop();
    }
}

vector<int> ans;
while(!min.empty()){
    ans.push_back(min.top());
    min.pop();
}

return ans;

}

int main(){
int arr[]={3,4,8,9,2,6,7};
int k;
cout<<"Enter k: "<<endl;
cin>>k;
vector<int> output=kSmallest(arr,7,k);
sort(output.begin(),output.end());

for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}
cout<<endl;
}

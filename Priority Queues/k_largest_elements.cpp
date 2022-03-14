/*
Code : K largest elements

You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25

*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;


vector<int> kLargest(int arr[],int n,int k){

priority_queue<int,vector<int>,greater<int>> max;  // this is the structure for built-in min

// we are using built in min; so everything act according to that

for(int i=0;i<k;i++){
    max.push(arr[i]);
}

for(int i=k;i<n;i++){
    if(max.top()<arr[i]){
        max.push(arr[i]);
        max.pop();
    }
}

vector<int> ans;
while(!max.empty()){
    ans.push_back(max.top());
    max.pop();
}

return ans;

}

int main(){
int arr[]={3,4,8,9,2,6,7};
int k;
cout<<"Enter k: "<<endl;
cin>>k;
vector<int> output=kLargest(arr,7,k);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}
cout<<endl;
}

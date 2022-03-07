#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int kthLargest(int arr[],int n,int k){

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

return max.top();

}

int main(){
int arr[]={3,4,8,9,2,6,7};
int k;
cout<<"Enter k: "<<endl;
cin>>k;
cout<<"Kth largest element: "<<kthLargest(arr,7,k)<<endl;
}


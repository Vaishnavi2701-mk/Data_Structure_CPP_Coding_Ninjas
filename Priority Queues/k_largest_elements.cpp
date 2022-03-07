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

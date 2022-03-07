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

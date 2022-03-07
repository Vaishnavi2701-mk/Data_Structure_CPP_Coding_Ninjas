#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> longestConsecutiveSequence(int *arr,int n){

unordered_map<int,int> map;
vector <int> ans;

for(int i=0;i<n;i++){
    map[arr[i]]=1;
}
int max=0;
int k=0;

for(int i=0;i<n;i++){
    int x=arr[i];
    int j=0;
    if(map.count(x-1)>0){
        continue;
    }
    while(map.count(x)>0){
        x++;j++;
    }
    if(j>max){
        max=j;
        k=arr[i];

    }
}

for(int i=0;i<max;i++){
    ans.push_back(k);
    k++;
}

vector<int> v;
v.push_back(ans[0]);
v.push_back(ans[ans.size()-1]);
return v;
}
int main(){

int arr[]={3,7,2,1,9,8,41};
vector<int> v=longestConsecutiveSequence(arr,7);
for(auto i=v.begin();i!=v.end();i++){
    cout<<*i<<" ";
}

}

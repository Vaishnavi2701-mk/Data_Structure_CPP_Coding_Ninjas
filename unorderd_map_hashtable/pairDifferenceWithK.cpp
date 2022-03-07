#include<iostream>
#include<unordered_map>
using namespace std;

int getPairWithDifferenceK(int *arr,int n, int k){

unordered_map<int,int> map;

int ans=0;

for(int i=0;i<n;i++){
    int comp=arr[i]+k;
    ans+=map[comp];
    if(k!=0){
    comp=arr[i]-k;
    ans+=map[comp];
    }
     map[arr[i]]++;

}

return ans;

}

int main(){
int arr[]={4,4,4,4};
int k;
cout<<"Enter the value of K:"<<endl;
cin>>k;

cout<<"Count of pairs: "<<getPairWithDifferenceK(arr,4,k)<<endl;
}

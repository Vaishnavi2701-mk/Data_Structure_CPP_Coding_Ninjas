#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int>removeDuplicates(int arr[],int size){

vector<int> output;
unordered_map<int,bool> seen;   // we will store the value like,{key{no.},value{if present true}}

for(int i=0;i<size;i++){

    if(seen.count(arr[i])>0){   // greater than 0 hai that means it already occures
        continue;
    }
    seen[arr[i]]=true;          //=0 ho gaya that means output main dalana hai
    output.push_back(arr[i]);

}
return output;

}

int main(){
int arr[]={1,2,3,3,5,6,6,4,1,2,6};
vector<int>output=removeDuplicates(arr,11);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}
}

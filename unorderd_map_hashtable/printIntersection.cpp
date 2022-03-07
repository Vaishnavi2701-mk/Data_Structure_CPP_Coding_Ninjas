#include<iostream>
#include<unordered_map>
using namespace std;

void printIntersection(int arr1[],int arr2[],int n,int m){

unordered_map<int,int> map;

//store value of every element from first array

for(int i=0;i<n;i++){
    map[arr1[i]]++;
}

// now if value of element from second array is more than 0 then it is intersection

for(int i=0;i<m;i++){
    if(map[arr2[i]]>0){
        map[arr2[i]]--;
        cout<<arr2[i]<<endl;
    }
}
}

int main(){
int arr1[]={2,3,4,5,6};
int arr2[]={2,4,3};

printIntersection(arr1,arr2,5,3);
}

#include<iostream>
#include<unordered_map>
using namespace std;
int highestFrequency(int arr[], int n) {
unordered_map<int,int> map;// we are getting key as an integer from array and value we will store it will be integer as well

    for(int i=0;i<n;i++){
        int key=arr[i];
        if(map.count(key)==0){
            map[key]=1;   // if key will occures one time then initiallize its value by 1;
        }
        else{
            map[key]++;  // if key occures more than one time then only update value;
        }
    }

    int maximum=map[arr[0]];   // consider 0th element have maximum occurence
    int element=arr[0];        // it will be 0th element

    int j=1;
    while(j<n){
        if(map[arr[j]]>maximum){   //if the next element of array will have greater value that previous one then update
            maximum=map[arr[j]];
            element=arr[j];
        }
        j++;
    }
    return element;

}

int main(){
int arr[]={2,12,2,4,5,2,3,4,6,7,4,2,2};
cout<<"highest frequency element: "<<highestFrequency(arr,13)<<endl;

}

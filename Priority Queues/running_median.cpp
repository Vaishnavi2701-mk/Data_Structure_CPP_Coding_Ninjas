#include<iostream>
#include<queue>
using namespace std;

void runningMedian(int arr[],int n){
// if array is empty

if(n==0){
    return;
}

// make min-heap and max-heap

priority_queue<int> max;
priority_queue<int,vector<int>,greater<int>>min;

int med=arr[0];
max.push(arr[0]);
cout<<med<<" ";

for(int i=1;i<n;i++){

    int x=arr[i];

    //case 1: when max heap is greater in size
    if(max.size()>min.size()){
        if(x<med){
            min.push(max.top());
            max.pop();
            max.push(x);
        }
        else{
            min.push(x);
        }
        med=(max.top()+min.top())/2.0;
    }

    //case 2: when both are equal in size
    else if(max.size()==min.size()){
        if(x<med){
            max.push(x);
            med=(int)max.top();
        }
        else{
            min.push(x);
            med=(int)min.top();
        }

    }

    //case 3: when min heap is greater in size
    else{


        if(x>med){

            max.push(min.top());
            min.pop();
            min.push(x);

        }
        else{
            max.push(x);
        }

        med=(max.top()+min.top())/2.0;

    }
     cout<<med<<" ";

}
}
int main(){

int arr[]={7,2,8,3,1,5};

cout<<"Running median: "<<endl;
runningMedian(arr,6);


}

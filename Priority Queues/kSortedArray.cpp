#include<iostream>
#include<queue>
using namespace std;

// we are sorting it in decreasing order; thats why in-built priority queue is applicable;

void kSortedArray(int input[],int n,int k){

priority_queue<int>pq;

//first insert first k elements in queue
for(int i=0;i<k;i++){
    pq.push(input[i]);
}

// starting index will be 0 and then from k to n one member will be increased because after inserting maximum it will be popped
int j=0;
for(int i=k;i<n;i++){
    input[j]=pq.top();
    pq.pop();
    pq.push(input[i]);
    j++;
}

// even after that last n-k elements will be not sorted  so sort them at the end;
while(!pq.empty()){
    input[j]=pq.top();
    pq.pop();
    j++;
}


}
int main(){

int input[]={10,12,6,7,9};
int k=3;

kSortedArray(input,5,k);
for(int i=0;i<5;i++){
    cout<<input[i]<<" ";
}


}

#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{

vector<int>pq;

public:
PriorityQueue(){


}

//check if queue is empty
bool isEmpty(){
return pq.size()==0;
}

//return size of queue
int getSize(){
return pq.size();
}

// return minimum of queue
int getMin(){
if(isEmpty()){
    return 0;
}
return pq[0];
}

// insert new elements by down heapify;
void insert (int element){
pq.push_back(element);
int childIndex=pq.size()-1;

while(childIndex>0){
    int parentIndex=(childIndex-1)/2;
    if(pq[childIndex]<pq[parentIndex]){
        int temp=pq[childIndex];
        pq[childIndex]=pq[parentIndex];
        pq[parentIndex]=temp;
          }
    else{
        break;
    }
    childIndex=parentIndex;
}
}

int removeMin(){
if(isEmpty()){
    return 0;
}
int ans=pq[0];
pq[0]=pq[pq.size()-1];
pq.pop_back();

int parentIndex=0;
int leftChildIndex=2*parentIndex+1;
int rightChildIndex=2*parentIndex+2;

while(leftChildIndex<pq.size()){
    int minIndex=parentIndex;
    if(pq[minIndex]>pq[leftChildIndex]){
        minIndex=leftChildIndex;
    }
    if(rightChildIndex<pq.size()&&pq[rightChildIndex]<pq[minIndex]){
        minIndex=rightChildIndex;
    }
    if(minIndex==parentIndex){
        break;
    }
    int temp=pq[minIndex];
    pq[minIndex]=pq[parentIndex];
    pq[parentIndex]=temp;

    parentIndex=minIndex;
     leftChildIndex=2*parentIndex+1;
     rightChildIndex=2*parentIndex+2;

}
   return ans;
}

};



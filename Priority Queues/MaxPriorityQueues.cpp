/*
Code : Max Priority Queue

Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

*/
#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {

    }

    //**************** Implement all the public functions here ***************//

    void insert(int element) {
        pq.push_back(element);
        int childIndex=pq.size()-1;

        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]>pq[parentIndex]){
                int temp=pq[parentIndex];
                pq[parentIndex]=pq[childIndex];
                pq[childIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int getMax() {
        if(pq.size()==0){
            return 0;
        }
        return pq[0];
    }

    int removeMax() {

        if(pq.size()==0){
            return 0;
        }

        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;

        while(leftChildIndex<pq.size()){
            int maxIndex=parentIndex;
            if(pq[maxIndex]<pq[leftChildIndex]){
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size()&&pq[rightChildIndex]>pq[maxIndex]){
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex){
                break;
            }

            int temp=pq[maxIndex];
            pq[maxIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex=maxIndex;
             leftChildIndex=2*parentIndex+1;
             rightChildIndex=2*parentIndex+2;

        }

        return ans;
    }

    int getSize() {
        return pq.size();
    }
     bool isEmpty() {
        return pq.size()==0;
    }


};

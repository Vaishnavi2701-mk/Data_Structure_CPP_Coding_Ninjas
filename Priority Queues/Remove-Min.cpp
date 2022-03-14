/*
Code : Remove Min

Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.
*/

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(isEmpty()){
            return 0;
        }
        
        int ans=pq[0];
        int endIndex=pq.size()-1;
        pq[0]=pq[endIndex];
        pq.pop_back();
        
        
        int pi=0;
        int leftCI=2*pi+1;
        int rightCI=2*pi+2;
        
        while(leftCI<pq.size()){
            int minIndex=pi;
            if(pq[minIndex]>pq[leftCI]){
                minIndex=leftCI;
            }
             if(rightCI<pq.size()&&pq[rightCI]<pq[minIndex]){
                minIndex=rightCI;
            }
            if(minIndex==pi){
                break;
            }
            int temp=pq[minIndex];
            pq[minIndex]=pq[pi];
            pq[pi]=temp;
            
            
            pi=minIndex;
            leftCI=2*pi+1;
            rightCI=2*pi+2;
        }
        return ans;
    }
};

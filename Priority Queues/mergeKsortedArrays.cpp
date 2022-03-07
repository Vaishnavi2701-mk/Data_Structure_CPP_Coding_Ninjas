#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> mergeKsortedArrays(vector<vector<int>*>input){

//output vector for final result

vector<int> output;
priority_queue<int,vector<int>,greater<int>>pq;

for(int i=0;i<input.size();i++){
    //store each array present in input vector in new vector
    vector<int>*q=input[i];
    //store each element of vector q in pq;

    for(int j=0;j<q->size();j++){
        pq.push(q->at(j));
    }
}

// now pq contain all the elements af all k arrays;
//we will push it in output vector ,as it is built-in min priority queueit will push minimum element first and everything goes on like this

while(!pq.empty()){
    output.push_back(pq.top());
    pq.pop();
}
return output;


}

int main(){

int k;
cout<<"Enter the number of arrays: "<<endl;
cin>>k;

vector<vector<int>*>input;

for(int j=1;j<=k;j++){
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;

    vector<int>*current=new vector<int>;

    for(int i=0;i<size;i++){
        int a;
        cin>>a;
        current->push_back(a);
    }
    input.push_back(current);
}

vector<int>output=mergeKsortedArrays(input);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}

}

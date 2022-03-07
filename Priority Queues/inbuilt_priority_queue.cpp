#include<iostream>
#include<queue>  //include queue while using in-built priority queue
using namespace std;

int main(){

priority_queue<int> pq;    // we have to specify inbuilt class priority_queue

pq.push(10);               // IMP it is inbuilt max-priority-queue
pq.push(14);
pq.push(190);
pq.push(45);
pq.push(78);
pq.push(134);
pq.push(34);

cout<<"Size: "<<pq.size()<<endl;
cout<<"Top(max): "<<pq.top()<<endl;
cout<<"Empty/Not: "<<(pq.empty()?"true\n":"false\n")<<endl;

cout<<"Heap sort using max-heap"<<endl;

while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
}

}

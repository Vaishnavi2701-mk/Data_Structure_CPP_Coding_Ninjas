#include<iostream>
#include<queue>
using namespace std;


int buyTicket(int arr[],int n, int k){

//made a simple queue and priority_queue

queue<int> q;
priority_queue<int> pq;

for(int i=0;i<n;i++){
    q.push(arr[i]);
    pq.push(arr[i]);
}

int time=0;

while(!pq.empty()){

    if(q.front()==pq.top()){

        if(k==0){
            return time+1;
        }
        else{
            time++;
            q.pop();
            pq.pop();
            k--;
        }

    }
    else{
        q.push(q.front());
        q.pop();
        if(k==0){
            k=q.size()-1;
        }
        else{
            k--;
        }
    }

}

return time;



}

int main(){

int arr[]={2,3,2,2,4};
int k;
cout<<"enter k: "<<endl;
cin>>k;

cout<<"Time taken for gaining the ticket for kth person is: "<<buyTicket(arr,5,k)<<endl;

}

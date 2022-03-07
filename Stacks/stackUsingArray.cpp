#include<climits>

class stackUsingArray{
int *data;
int nextIndex;
int capacity;

public:
    stackUsingArray(int totalSize){
    data=new int(totalSize);
    nextIndex=0;
    capacity=totalSize;
    }

int size(){
return nextIndex;
}

bool isEmpty(){
/*if(nextIndex==0){
        return true;
}
else{
    return false;
}*/
return nextIndex==0;
}
void push(int element){
    if(nextIndex==capacity){
        cout<<"stack is full"<<endl;
        return;
    }
data[nextIndex]=element;
nextIndex++;
}

int pop(){
    if(isEmpty()){
        cout<<"stack is full"<<endl;
        return INT_MIN;
    }
nextIndex--;
return data[nextIndex];
}

int top(){
      if(isEmpty()){
        cout<<"stack is full"<<endl;
        return INT_MIN;
    }
return data[nextIndex-1];
}


};

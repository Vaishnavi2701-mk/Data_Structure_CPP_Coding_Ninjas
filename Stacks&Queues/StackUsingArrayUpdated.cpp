// in the previous example we had seen that if array size gets exhausted we cant push the elements but we can remove this constrain;


#include<climits>

class stackUsingArray{
int *data;
int nextIndex;
int capacity;

public:
  //changes
    stackUsingArray(){
    data=new int(4);
    nextIndex=0;
    capacity=4;
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
    //changes
    if(nextIndex==capacity){
        int *newData=new int[2*capacity];
        for(int i=0;i<capacity;i++){
            newData[i]=data[i];
        }
        capacity*=2;
        delete[]data;
        data=newData;
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

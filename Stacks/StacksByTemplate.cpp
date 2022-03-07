template <typename T>
class stackUsingArray{
T *data;
int nextIndex;
int capacity;

public:
  //changes
    stackUsingArray(){
    data=new T(4);
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
void push(T element){
    //changes
    if(nextIndex==capacity){
        T *newData=new T[2*capacity];
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

T pop(){
    if(isEmpty()){
        cout<<"stack is full"<<endl;
        return 0;                        // if we return INT_MIN it will be valid only in the case of integer but if we return 0 then it will be valid in case of character as well because 0 is for NULL;
    }
nextIndex--;
return data[nextIndex];
}

T top(){
      if(isEmpty()){
        cout<<"stack is full"<<endl;
        return 0;
    }
return data[nextIndex-1];
}


};


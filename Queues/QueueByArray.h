template <typename T>
class QueueByArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    //constructor;
    QueueByArray(int s){
        data=new T[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }

    //no of elements;

    int getSize(){
        return size;
    }

    //empty or not;

    bool isEmpty(){
    return size==0;
    }

    //insert element;

    void enqueue(T element){
        if(size==capacity){
            cout<<"Queue is full!"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        size++;
        if(firstIndex==-1){
            firstIndex=0;
        }
    }

    // return top element
    T front (){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    // delete first element and return it;
    T dequeue(){
         if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        // even if we didn't do it; it will manage as it is;
        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;
    }



};

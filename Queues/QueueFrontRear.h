class Deque{
  int *deque;
  int capacity;
  int front;
  int rear;

  public:
  Deque (int size){
  deque=new int [size];
  capacity=size;
  front=-1;
  rear=-1;
  }

  void insertFront(int element){

      if(front==-1 && rear==-1){
        front=0;
        rear=0;
        deque[front]=element;
      }
      if((front+1)%capacity==rear){
        cout<<-1<<endl;
        return;
      }
      front=(front+1)%capacity;
      deque[front]=element;

  }

  void insertRear(int element){
  if(front==-1&&rear==-1){
    front=0;
    rear=0;
    deque[rear]=element;

  }
  if(front==rear-1||rear==0&&front==capacity-1){
    cout<<-1<<endl;
    return;
  }
  if(rear==0){
    rear=capacity-1;
  }
  else{
    rear--;
  }
  deque[rear]=element;


  }

  void deleteFront(){
      if(front==-1&&rear==-1){
         cout<< -1<<endl;
         return;
        }
     if(front==rear){
        front=-1;
        rear=-1;
        return;
     }
     if(front==0){
        front=capacity-1;
     }
     else{
        front--;
     }

  }

  void deleteRear(){
     if(front==-1&&rear==-1){
         cout<<-1<<endl;
         return;
        }
     if(rear==front){
        front=-1;
        rear=-1;
        return;
     }
     rear=(rear+1)%capacity;

  }

  int getFront(){
  if(front==-1&&rear==-1){
    return -1;
  }
  return deque[front];
  }

  int getRear(){
  if(front==-1&&rear==-1){
    return -1;
  }
  return deque[rear];
  }





};



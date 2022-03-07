#include"Car.cpp"
#include"Truck.cpp"


class Bus: public Car,public Truck{

public:
    Bus(){
    cout<<"Bus Default Constructor: "<<endl;
    }

    ~Bus(){
    cout<<"Bus Default Destructor: "<<endl;
    }

    void print(){
      cout<<"Bus"<<endl;
    }

};

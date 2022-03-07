#include"Vehicle.h"

class Truck: public Vehicle{

public:

    Truck(){
    cout<<"Truck Default Constructor: "<<endl;
    }

    ~Truck(){
    cout<<"Truck Default Destructor: "<<endl;
    }

    void print(){
      cout<<"Truck"<<endl;
    }


};

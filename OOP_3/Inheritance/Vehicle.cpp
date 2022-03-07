#include<iostream>
using namespace std;

class Vehicle{

private:
    int maxSpeed;
protected:
    int numTyres;
public:
    string colour;
};

class Car: private Vehicle{

public:
    int numGears;

    void print(){
    cout<<"Number of tyres: "<<numTyres<<endl;
    //cout<<"Max Speed: "<<maxSpeed<<endl;
    cout<<"Colour: "<<colour<<endl;
    cout<<"NumGear: "<<numGears<<endl;

    }

};


class ComplexNumber{
private:
    int real;
    int imaginary;
public:
    ComplexNumber(int real,int imaginary){
    this->real=real;
    this->imaginary=imaginary;
    }
    void print(){
    cout<<this->real<<" + "<<"i"<<this->imaginary<<endl;
    }
    void plus(ComplexNumber const&c2){
    int realPart=real+c2.real;
    int imaginaryPart=imaginary+c2.imaginary;
    real=realPart;
    imaginary=imaginaryPart;
    }
    void multiply(ComplexNumber const&c2){
    int realPart=(real*c2.real)-(imaginary*c2.imaginary);
    int imaginaryPart=(real*c2.imaginary)+(imaginary*c2.real);
    real=realPart;
    imaginary=imaginaryPart;
    }

};

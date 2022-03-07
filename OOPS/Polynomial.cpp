
class Polynomial {

    public:
    int *degCoeff;      // we are using this one in the main function so make it public;
    int capacity;
    //constructor
    Polynomial(){
        this->degCoeff=new int[6];
        this->capacity=5;
    }
    //parametrize constructor
    Polynomial (int capacity){
        this->degCoeff=new int[capacity+1];
        this->capacity=capacity;
    }
    //copy constructor
    Polynomial (Polynomial const &p){
        //deep copy;
        int *degNew=new int[p.capacity+1];

        for(int i=0;i<=p.capacity;i++)
            degNew[i]=p.degCoeff[i];

        this->degCoeff=degNew;

        this->capacity=p.capacity;
    }
    // copy assignment operator
       void operator=(Polynomial const &p){
        int *degNew=new int[p.capacity+1];
        //Copy the contents
        for(int i=0;i<=p.capacity;i++)
            degNew[i]=p.degCoeff[i];


        this->degCoeff=degNew;

        this->capacity=p.capacity;
    }
     // setCoefficient method
    void setCoefficient(int deg,int coef){
        if(deg>capacity){
            int capacityNew=deg;
            int *degNew=new int[capacityNew+1];
            for(int i=0;i<=capacity;i++)
                degNew[i]=degCoeff[i];

            this->degCoeff=degNew;
            this->capacity=capacityNew;
            degCoeff[deg]=coef;
        }
        else{
            degCoeff[deg]=coef;
        }
    }
    // add
    Polynomial operator+(Polynomial const &P2){

        int capacityNew=max(this->capacity,P2.capacity);

        Polynomial P3(capacityNew);

        for(int i=0;i<=capacityNew;i++){
            if(i<=capacity && i<=P2.capacity)
                P3.degCoeff[i]=this->degCoeff[i]+P2.degCoeff[i];
            else if(i<=capacity)
                P3.degCoeff[i]=this->degCoeff[i];
            else
                P3.degCoeff[i]=P2.degCoeff[i];
        }

        return P3;
    }

    //subtract

    Polynomial operator-(Polynomial const &P2){

        int capacityNew=max(this->capacity,P2.capacity);
        Polynomial P3(capacityNew);

        for(int i=0;i<=capacityNew;i++){
            if(i<=capacity && i<=P2.capacity)
                P3.degCoeff[i]=this->degCoeff[i]-P2.degCoeff[i];
            else if(i<=capacity)
                P3.degCoeff[i]=this->degCoeff[i];
            else
                P3.degCoeff[i]=-P2.degCoeff[i];
        }

        return P3;
    }

   // multiply

    Polynomial operator*(Polynomial const &P2){

        int capacityNew=this->capacity+P2.capacity;
        Polynomial P3(capacityNew);

        for(int i=0;i<=this->capacity;i++){

            for(int j=0;j<=P2.capacity;j++){
                P3.degCoeff[i+j]+=this->degCoeff[i]*P2.degCoeff[j];
            }
        }
        return P3;
    }
  //print

    void print(){

        for(int i=0;i<=this->capacity;i++){
            if(degCoeff[i]!=0)
                cout<<degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }

};


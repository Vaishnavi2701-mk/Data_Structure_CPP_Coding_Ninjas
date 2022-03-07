class Fraction{

private:
    int numerator;
    int denominator;
public:
   Fraction(int numerator, int denominator){
   this->numerator=numerator;
   this->denominator=denominator;
   }

 void print() const{
 cout<<this->numerator<<"/"<<this->denominator<<endl;
 }

 void simplify(){
 int gcd=1;
 int j=min(this->numerator,this-> denominator);
 for(int i=1;i<=j;i++){
    if(this->numerator%i==0&&this->denominator%i==0){
             gcd=i;
        }
 }
this->numerator=this->numerator/gcd;
this->denominator=this->denominator/gcd;
 }
Fraction add(Fraction const &f2) const{                 // need to change the return type because I wanted to store the result in the new object;
 int lcm=denominator*f2.denominator;
 int x=lcm/denominator;
 int y=lcm/f2.denominator;
 int numtr=x*numerator+(y*f2.numerator);

 //numerator=numtr;
 //denominator=lcm;          now we don't have to store it into f1 so this step is not true;

 Fraction fNew(numtr,lcm);     // we want result in third one so make the new one; and return it;
 fNew.simplify();
 return fNew;


 }
 // we can do same thing in quite different way by using operator overloading;

 Fraction operator+(Fraction const &f2)const{             // only change is operator overloading
 int lcm=denominator*f2.denominator;
 int x=lcm/denominator;
 int y=lcm/f2.denominator;
 int numtr=x*numerator+(y*f2.numerator);

 Fraction fNew(numtr,lcm);
 fNew.simplify();
 return fNew;


 }
 Fraction operator*(Fraction const &f2)const{
 int num=numerator*f2.numerator;
 int deno=denominator*f2.denominator;
 Fraction fNew(num,deno);
 fNew.simplify();
 return fNew;
 }


 void multiply(Fraction const &f2){
 numerator=numerator*f2.numerator;
 denominator=denominator*f2.denominator;
 simplify();
 }
 //checking operator

 bool operator==(Fraction const&f2) const{
 return (numerator==f2.numerator&&denominator==f2.denominator);   // it will only gives true or false;
 }

 // pre-increment;
 Fraction& operator++(){
 numerator=numerator+denominator;
 simplify();

 return *this;  // we are returning the value of incremented f1;so the function is already calling for f1 but in this key word but he thing is that we dont have to return address so return it by dereferencing;
 }

 //post-increment;(things will be quit different)

 Fraction operator ++(int){

 Fraction fNew(numerator,denominator);     // it is storing initial value of f1 before increment;
 numerator=numerator+denominator;          // this address with f1 so changes will happen in f1 only;
 simplify();
 fNew.simplify();                          // simplifying the initial value as well;
 return fNew;                              // this fNew will return to f3 as no incremented value;

 }

 //+=operator;

Fraction& operator+=(Fraction const&f2){
 int lcm=denominator*f2.denominator;
 int x=lcm/denominator;
 int y=lcm/f2.denominator;
 int numtr=x*numerator+(y*f2.numerator);

numerator=numtr;
denominator=lcm;
simplify();

return *this;


}

 };


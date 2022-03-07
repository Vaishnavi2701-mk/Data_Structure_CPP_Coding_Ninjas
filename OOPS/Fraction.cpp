class Fraction{

private:
    int numerator;
    int denominator;   // don't want that someone changes the value randomly; so declared as private;

public:
    // constructor without parameters;
    Fraction() {


    }
   // i don't want that my fraction takes the garbage value so create parametric constructor;
   Fraction(int numerator, int denominator){
   this->numerator=numerator;
   this->denominator=denominator;
   }

int getNumerator()const{
return numerator;
}
int getDenominator() const{
return denominator;
}
void setNumerator(int n) const{
numerator=n;
}
void setDenominator(int d){
denominator=d;
}

 void print() const{
 cout<<this->numerator<<"/"<<this->denominator<<endl;
 //cout<<numerator<<"/"<<denominator<<endl;  even if I don't write this int this case its fine because when I call the function f1.print that means it is already containing the address of f1;
 }

 void simplify(){
 int gcd=1;
 int j=min(this->numerator,this-> denominator);    // even if we don't write this its all fine;
 for(int i=1;i<=j;i++){
    if(this->numerator%i==0&&this->denominator%i==0){
             gcd=i;
        }
 }
this->numerator=this->numerator/gcd;
this->denominator=this->denominator/gcd;
//this way also because it already contains address of f1;
/* numerator=numerator/gcd;
 denominator=denominator/gcd;*/
 }
 void add(Fraction const &f2){        // making it constant reference to avoid copy and time taken;
 int lcm=denominator*f2.denominator;
 int x=lcm/denominator;
 int y=lcm/f2.denominator;
 int numtr=x*numerator+(y*f2.numerator);

 numerator=numtr;  // that means f1 ke numerator ko update karva do;
 denominator=lcm;  // f1 ke denominator bhi;

 simplify();        // indirectly calling f1.simplify;


 }
 void multiply(Fraction const &f2){
 numerator=numerator*f2.numerator;
 denominator=denominator*f2.denominator;
 simplify();
 }
 };

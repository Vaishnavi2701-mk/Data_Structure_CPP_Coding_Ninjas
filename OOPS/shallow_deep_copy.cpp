class Student{
   int age;
   char *name;
   public:
       Student(int age,char*name){
       this->age=age;
       //shallow copy (because it is receiving address it will print the changes as well);
       //this->name=name;

       //deep copy;

       this->name=new char(strlen(name)+1);
       strcpy(this->name,name);
       }
       void print(){
       cout<<age<<" "<<name<<endl;
       }



};



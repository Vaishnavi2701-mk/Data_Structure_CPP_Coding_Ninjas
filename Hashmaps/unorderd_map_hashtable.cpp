#include<iostream>
#include<string>
#include<unordered_map>//we are using hashtable so use this file;
using namespace std;

int main(){

unordered_map<string, int> ourmap;
// unordered map is in-built tempelate
// so key-value pair is there and they have in-built pair

//insert
pair<string, int> p("abc",1);
//when we want to insert it is inserted by making pair

ourmap.insert(p);

//other way
ourmap["def"]=1;

//find/access

//1 way
cout<<ourmap["abc"]<<endl;
//2 way
cout<<ourmap.at("abc")<<endl;

//if key is not present;

//cout<<ourmap.at("gci")<<endl;//if not present then by accessing by at it will give an error
cout<<ourmap.size()<<endl;
cout<<ourmap["gci"]<<endl;// but if I am accessing by [] it will not give an error but automatically insert it; value will be 0
cout<<ourmap.size()<<endl;// now it will give me 3 because insert ho chuka hai


//check presence

if(ourmap.count("gci")>0){
    cout<<"string is present: "<<endl;
}
else{
    cout<<"string is not present: "<<endl;
}

//erase/delete

ourmap.erase("gci");
cout<<ourmap.size()<<endl;
if(ourmap.count("gci")>0){
    cout<<"string is present: "<<endl;
}
else{
    cout<<"string is not present: "<<endl;
}


}

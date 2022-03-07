#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main(){

//we cant iterate over unordered_map normally like an array
//so we will use iterator

unordered_map<string,int>ourmap;

ourmap["abc"]=1;
ourmap["abc1"]=2;
ourmap["abc2"]=3;
ourmap["abc3"]=4;
ourmap["abc4"]=5;
ourmap["abc5"]=6;

unordered_map<string,int>::iterator it=ourmap.begin();  //we will initialize our map with begin of a map
// iterator it will act as a pointer it will store an address

while(it!=ourmap.end()){
        // unordered map it is so sequence can be altered;
    cout<<"Key: "<<it->first<<" "<<"Value: "<<it->second<<endl;
    it++;
}

//find (we can use find function by using iterator

    unordered_map<string,int>::iterator it3=ourmap.find("abc");    //this means noe we are finding that string and give it as first;
    while(it3!=ourmap.end()){
        // unordered map it is so sequence can be altered;
    cout<<"Key: "<<it3->first<<" "<<"Value: "<<it3->second<<endl;
    it3++;
}


//erase

ourmap.erase(it3,it3 + 1);



// we can iterate over a vector as well;

vector<int>v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.push_back(6);

vector<int>::iterator it2=v.begin();
while(it2!=v.end()){
        //vector ordered hota hai;
    cout<<*it2<<endl;
    it2++;
}


}

#include<iostream>
using namespace std;
#include<vector>

int main(){
//dynamic vector

//vector <int> *vp=new vector <int> ();

//static creation;


vector <int> v;

//lets insert the elements by using loop;
/*for(int i=0;i<100;i++){
    v.push_back(i+1);
    cout<<v.size()<<endl;
}*/

for(int i=0;i<100;i++){
    cout<<"capacity: "<<v.capacity()<<endl;
    cout<<"size: "<<v.size()<<endl;
    v.push_back(i+1);
}

v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);

v[2]=100;         //we can update the value

//after 40 if there is no push_back then they are going to print cut size will not increase it will be only 4 because inserting like this is illogical;
v[4]=245;
v[5]=56;    // thus we will only use [] bracket for updating and accessing values;

// now after push back it will consider this two values;
v.push_back(34);
v.push_back(78);

// deleting the elements

v.pop_back();

/*for (int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
}*/

/*cout<<v[0]<<endl;
cout<<v[1]<<endl;
cout<<v[2]<<endl;
cout<<v[3]<<endl;
cout<<v[4]<<endl;
cout<<v[5]<<endl;
cout<<v[6]<<endl;    // it will print garbage;

cout<<v.size()<<endl;

cout<<v.at(2)<<endl;    // it is like [] for accessing;
cout<<v.at(6)<<endl; */   // but is more reliable because it will not give garbage and execute that it is out of the range


}


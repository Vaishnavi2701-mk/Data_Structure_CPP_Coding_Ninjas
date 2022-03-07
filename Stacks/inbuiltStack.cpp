#include<iostream>
using namespace std;
#include <stack>

int main(){
    //changes
stack <char> st;

st.push(101);
st.push(102);
st.push(103);
st.push(104);
st.push(105);
st.push(106);

cout<<st.top()<<endl;
//changes
st.pop();

cout<<st.top()<<endl;

cout<<st.size()<<endl;
//changes
cout<<st.empty()<<endl;
}






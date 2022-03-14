#include<iostream>
#include"Tries.h"
using namespace std;

int main(){

Tries t;

t.insertWord("and");
t.insertWord("are");
t.insertWord("dot");

cout<<(t.searchWord("are")?"true\n":"fasle\n")<<endl;

cout<<(t.searchWord("dot")?"true\n":"fasle\n")<<endl;

t.removeWord("are");
t.removeWord("and");


cout<<(t.searchWord("are")?"true\n":"fasle\n")<<endl;

cout<<(t.searchWord("and")?"true\n":"fasle\n")<<endl;



}

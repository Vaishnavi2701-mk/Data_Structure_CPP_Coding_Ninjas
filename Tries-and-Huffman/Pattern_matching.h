/*
Pattern Matching

Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains a string, that denotes the value of the pattern p.
Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
de
Sample Output 2 :
true
Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true
Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false
*/

#include<string>
#include<vector>
using namespace std;
#include "Trienode.h"

class pattern_matching{

TrieNode * root;
public:
     int count;
pattern_matching(){
root=new TrieNode['\0'];
this->count=0;
}

bool insertWord(TrieNode*root,string word){

//base case
if(word.size()==0){
    if(!root->isTerminal){
        root->isTerminal=true;
        return true;
    }
    //this means word is already present thats why isTerminal==true;
    else{
        return false;
    }
}

//small calculation
int index=word[0]-'a';
TrieNode*child;

//if that letter is present then termed it as child;
if(root->children[index]!=NULL){
    child=root->children[index];
}
// if not present create a new node and then termed it as child;
else{
    child=new TrieNode(word[0]);
    root->children[index]=child;
}
//Recursive call
insertWord(child,word.substr(1));

}

void insertWord(string word){
  if(insertWord(root,word))
    this->count++;
}

bool searchPattern(TrieNode*root,string word){

if(word.size()==0){
    return true;
}
if(root->children[word[0]-'a']==NULL){
    return false;
}

return searchPattern(root->children[word[0]-'a'],word.substr(1));
}

bool searchPattern(string word){
 return searchPattern(root,word);
}

bool patternSearch(vector<string> vect,string pattern){
for(int i=0;i<vect.size();i++){
    while(vect[i].size()!=NULL){
        insertWord(vect[i]);
        vect[i]=vect[i].substr(1);
    }
}
return searchPattern(pattern);
}

};

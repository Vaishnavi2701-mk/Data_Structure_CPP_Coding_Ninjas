#include"Trienode.h"
#include<string>
using namespace std;
class Tries{

TrieNode * root;

public:
    Tries(){

    root=new TrieNode('\0');

    }
//INSERT

void insertWord(TrieNode*root, string word){
//base case
if(word.size()==0){
    root->isTerminal=true;
    return;
}
//small calculation;
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
 insertWord(root,word);
}

// SEARCH

bool searchWord(TrieNode*root,string word){
int index=word[0]-'a';
//base case
if(root->children[index]==NULL){
    return false;
}
//small calculation
if(word.size()==1){
    return root->children[index]->isTerminal;
}
/*if(word.size()==0){
  return root->isTerminal;
}
*/
 searchWord(root->children[index],word.substr(1));
}
bool searchWord(string word){
 return searchWord(root,word);
}


//REMOVE

void removeWord(TrieNode*root,string word){
    //base case
    if(word.size()==0){
        root->isTerminal=false;
        return;
    }
    //small calculation
    TrieNode*child;
    int index=word[0]-'a';
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return;
    }
    //recursion
    removeWord(child,word.substr(1));

    //Remove nodes if they are useless

    //Must satisfy two conditions
    //1) there should be no end on that letter
    if(child->isTerminal==false){
            //2) there should be no further child of that letter
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL){
                // even if the one child is present we will return;
                return;
            }
        }
        delete child;
        root->children[index]=NULL;
    }

}

void removeWord(string word){
    removeWord(root,word);
}
};

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool bfs(vector<vector<bool>>&board,int n,int m,int i,int j,vector<vector<bool>>&visited,string s){

if(s.size()==0){
    return true;
}
visited[i][j]=true;
bool ans=false;

//8 possible directions
//down
if(i+1<n && !visited[i+1][j] && board[i+1][j]==s[0]){
    if(bfs(board,n,m,i+1,j,visited,s.substr(1)))
        return true;
}
//up
if(i-1>=0 && !visited[i-1][j] && board[i-1][j]==s[0]){
    if(bfs(board,n,m,i-1,j,visited,s.substr(1)))
        return true;
}
//left
if(j-1>=0 && !visited[i][j-1] && board[i][j-1]==s[0]){
    if(bfs(board,n,m,i,j-1,visited,s.substr(1)))
        return true;
}
//right
if(j+1<m && !visited[i][j+1] && board[i][j+1]==s[0]){
    if(bfs(board,n,m,i,j+1,visited,s.substr(1)))
        return true;
}
//down left
if(i+1<n && j-1>=0 && !visited[i+1][j-1] && board[i+1][j-1]==s[0]){
    if(bfs(board,n,m,i+1,j-1,visited,s.substr(1)))
        return true;
}
//down right
if(i+1<n && j+1<m &&!visited[i+1][j+1] && board[i+1][j+1]==s[0]){
    if(bfs(board,n,m,i+1,j+1,visited,s.substr(1)))
        return true;
}
//up left
if(i-1>=0 && j-1>=0 && !visited[i-1][j-1] && board[i-1][j-1]==s[0]){
    if(bfs(board,n,m,i-1,j-1,visited,s.substr(1)))
        return true;
}
//up right
if(i-1>=0 && j+1<m && !visited[i-1][j+1] && board[i-1][j+1]==s[0]){
    if(bfs(board,n,m,i-1,j+1,visited,s.substr(1)))
        return true;
}
visited[i][j]=false;
return ans;
}

bool hasPath(vector<vector<char>>&board,int n,int m){


vector<vector<bool>> visited(n,vector<bool>(m,false));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]=='C'){
            string s="ODINGNINJA";
            if(bfs(board,n,m,i,j,visited,s)){
                return true;
            }
        }
    }
}
return false;

}

int main(){

int n,m;
cin>>n>>m;

vector<vector<char>> board=(n,vector<char>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>board[i][j];
    }
}

cout<<hasPath(board,n,m)<<endl;


}

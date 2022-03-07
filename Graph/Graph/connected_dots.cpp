#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<char>>&board,vector<vector<bool>>&visited,int i,int j,int p){

//p is a parent for which we need to check cycle
// below is a check to avoid out of bound

if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=p){
    return false;
}
if(visited[i][j]){
    return true;
}

visited[i][j]=true;

// temporarily remove the current that it shouldn't go back and call recursion further;
board[i][j]='.';
bool exist=dfs(board,visited,i-1,j,p)||dfs(board,visited,i+1,j,p)||dfs(board,visited,i,j-1,p)||dfs(board,visited,i,j+1,p);
board[i][j]=p;
return exist;

}


bool hasCycle(vector<vector<char>>&board,int n,int m){

vector<vector<bool>> visited(n,vector<bool>(m,false));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!visited[i][j] && dfs(board,visited,i,j,board[i][j])){
            return true;
        }
    }
}

return false;

}


int main(){

int n,m;
cin>>n>>m;
vector<vector<char>> board(n,vector<char>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>board[i][j];
    }
}

cout<<(hasCycle(board,n,m)?"true":"false");

}

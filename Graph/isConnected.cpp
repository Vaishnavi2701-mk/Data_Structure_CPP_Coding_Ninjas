#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;
#include<vector>

void isConnected(int **edges,int n,int sv,bool *visited){

//base case
if(n==1){
    visited[sv]=true;
    return;
}
visited[sv]=true;
for(int i=0;i<n;i++){
    if(edges[sv][i]==1&&!visited[i]){
        isConnected(edges,n,i,visited);
    }
}

return;

}
int main()
{
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }

    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;

    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;

    }
   isConnected(edges,n,0,visited);
   int i;
   for( i=0;i<n;i++){
    if(visited[i]==false){
        cout<<"false"<<'\n';
        break;
        return 0;
    }
   }
   if(i==n)
   cout<<"true"<<'\n';
   return 0;

   delete [] visited;

for(int i=0;i<n;i++){
    delete [] edges[i];
}
delete []edges;
}

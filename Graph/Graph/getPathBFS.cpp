#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;
#include<vector>
vector<int>*getPathBFS(int **edges,int n,int sv,int ev){

bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
queue<int>q;
q.push(sv);
visited[sv]=true;
bool done=false;
unordered_map<int,int> parent;
while(!q.empty()&&!done){
    int front=q.front();
    q.pop();
    for(int i=0;i<n;i++){
        if(edges[front][i]==1&& !visited[i]){
            parent[i]=front;
            q.push(i);
            visited[i]=true;
            if(i==ev){
                done=true;
                break;
            }
        }
    }
}

delete [] visited;
if(!done){
    return NULL;
}
else{
    vector<int>*output=new vector<int>();
    int current=ev;
    output->push_back(ev);
    while(current!=sv){
        current=parent[current];
        output->push_back(current);
    }
    return output;
}


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
  int v1,v2;
  cin>>v1>>v2;
  vector<int> *output=getPathBFS(edges,n,v1,v2);
  if(output==NULL) return 0;

  for(int i=0;i<output->size();i++)
  {
    cout<<output->at(i)<<" ";
  }

for(int i=0;i<n;i++){
    delete [] edges[i];
}
delete []edges;
}


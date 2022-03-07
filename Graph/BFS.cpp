#include<iostream>
#include<queue>
using namespace std;

void bfs(int ** graph, int n ,int sv){
bool *visited=new bool [n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
    queue<int> que;
    que.push(sv);
    visited[sv] =true;

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        cout<<v<<" ";

        for(int i = 0; i < n; i++)
        {
            if(i == sv)
            {
                continue;
            }

            if(graph[v][i] == 1 && !visited[i])
            {
                visited[i] = true;
                que.push(i);
            }

        }
    }

delete [] visited;
}


int main(){

    int n,e;
    cin >> n >> e;

    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    bfs(graph,n,0);

for(int i=0;i<n;i++){
    delete [] graph[i];
}
delete [] graph;

}

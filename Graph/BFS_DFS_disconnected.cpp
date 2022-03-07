#include<iostream>
#include<queue>
using namespace std;

void printBFS(int ** graph, int n ,int sv,bool * visited){
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

}
void printDFS(int** edges,int n,int sv,bool * visited){
cout<<sv<<" ";
visited[sv]=true;
for(int i=0;i<n;i++){
    if(i==sv){
        continue;
    }
    if(edges[sv][i]==1){
        if(visited[i]){
            continue;
        }
        printDFS(edges,n,i,visited);
    }
}

}

void DFS(int **edges,int n){
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
    //IMP
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,/*sv*/i,visited);
        }
    }

delete [] visited;
}

void BFS(int **edges,int n){
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
    //IMP
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,/*sv*/i,visited);
        }
    }

delete [] visited;
}
int main(){
int n,e;
cin>>n>>e;
int ** edges=new int*[n];
for(int i=0;i<n;i++){
    edges[i]=new int [n];
    for(int j=0;j<n;j++){
        edges[i][j]=0;
    }
}

for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;

}
cout<<"print BFS"<<endl;
BFS(edges,n);
cout<<endl;
cout<<"print DFS"<<endl;
DFS(edges,n);

}

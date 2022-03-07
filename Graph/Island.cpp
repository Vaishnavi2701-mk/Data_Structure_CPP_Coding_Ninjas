#include <iostream>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

void BFS(bool **edges,int n,int sv,int *visited){

    queue<int> q;
    q.push(sv);
    visited[sv]=1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i=0;i<n;i++)
        {
            if(edges[x][i] && !visited[i] &&i!=x )
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    }

void BFS(bool ** edges,int n){
int *visited = new int[n];
    for(int i=0;i<n;i++)
    	visited[i] = 0;

    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(edges,n,i,visited);
            ans++;
        }
    }
    cout<<ans;
}
int main()
{
    int n,e;
    cin >> n >> e;

    bool** edges = new bool*[n];
    for(int i=0; i<n; i++){
        edges[i]=new bool[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f;
        cin>>s;

        edges[f][s]=1;
        edges[s][f]=1;


    }
   BFS(edges,n);

  return 0;
}

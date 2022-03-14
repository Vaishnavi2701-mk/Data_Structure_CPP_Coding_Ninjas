/*
Islands

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 */

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

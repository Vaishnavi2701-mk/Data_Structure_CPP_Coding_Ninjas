#include<iostream>
#include<climits>
using namespace std;

int findMinvertex(int *distance,bool * visited,int n){

int minVertex=-1;
for(int i=0;i<n;i++){
    if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex])){
        minVertex=i;
    }
}
return minVertex;
}

void dijikstra(int ** edges,int n){

int * distance= new int [n];
bool * visited=new bool [n];

for(int i=0;i<n;i++){
    visited[i]=false;
    distance[i]=INT_MAX;
}

distance[0]=0;
for(int i=0;i<n-1;i++){
    int minVertex=findMinvertex(distance,visited,n);
    visited[minVertex]=true;

    for(int j=0;j<n;j++){
        if(edges[minVertex][j]!=0 && !visited[j]){
            int dist=distance[minVertex]+edges[minVertex][j];
            if(dist<distance[j]){
                distance[j]=dist;
            }
        }
    }
}

//print MST

cout<<endl;
cout<<"print MST: "<<endl;
for(int i=0;i<n;i++){
    cout<<i<<" "<<distance[i]<<endl;
}

}

int main(){
int n,e;
cin>>n>>e;

int ** edges=new int *[n];
for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<n;j++){
        edges[i][j]=0;
    }
}

for(int i=0;i<e;i++){
    int f,s,w;
    cin>>f>>s>>w;
    edges[f][s]=w;
    edges[s][f]=w;
}
dijikstra(edges,n);

for(int i=0;i<n;i++){
    delete [] edges[i];
}
delete [] edges;
return 0;

}


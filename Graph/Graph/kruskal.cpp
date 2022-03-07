#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
int source;
int destination;
int weight;
};

bool compare(Edge e1,Edge e2){
return e1.weight<e2.weight;
}

int findParent(int v,int *parent){

if(parent[v]==v){
    return v;
}
return findParent(parent[v],parent);

}
void kruskal(Edge * input,int n,int e){

//sort the array in ascending order based on weight
sort(input,input+e,compare);

Edge *output=new Edge[n-1];// n-1 edges consider for MST
int *parent=new int[n];
for(int i=0;i<n;i++){
    parent[i]=i;
}
int count=0;
int i=0;
while(count!=n-1){
    Edge currentEdge=input[i];
    //check if we can add the currentEdge in the MST;

    int sourceParent=findParent(currentEdge.source,parent);
    int destParent=findParent(currentEdge.destination,parent);

    if(sourceParent!=destParent){
        output[count]=currentEdge;
        count++;
        // make one parent child of another;
        parent[sourceParent]=destParent;
            }
            i++;
}

//print MST
cout<<endl;
cout<<"Print MST"<<endl;
for(int i=0;i<n-1;i++){
    if(output[i].source<output[i].destination){
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }
    else{
        cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
}

}

int main(){
int n,e;
cin>>n>>e;

Edge * input=new Edge[e];

for(int i=0;i<e;i++){
    int s,d,w;
    cin>>s>>d>>w;
    input[i].source=s;
    input[i].destination=d;
    input[i].weight=w;
}
kruskal(input,n,e);
return 0;
}

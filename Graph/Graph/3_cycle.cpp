#include<iostream>
using namespace std;

int solve(bool **edges,int n){

int count=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(edges[i][j]==1&&i!=j){
            for(int k=0;k<n;k++){
                if(j!=k && k!=i && edges[j][k]==1 &&edges[i][k]==1){
                    count++;
                }
            }
        }
    }
}
 return count/6;

}
int main(){

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
   cout<<solve(edges,n);

  return 0;


}

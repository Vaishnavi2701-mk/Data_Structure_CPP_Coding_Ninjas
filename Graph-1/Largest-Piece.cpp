/*
Largest Piece

It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/

#include <iostream>
#include<climits>
#include <vector>
using namespace std;

static int rowNbr[]={-1,1,0,0};
static int colNbr[]={0,0,-1,1};

bool iseligible(vector<vector<int>>&cake,int x,int y,int **visited,int n){
    if(x<0 || x>=n || y<0 || y>=n || visited[x][y]==1 ||cake[x][y]==0){
        return 0;
    }
    else
        return 1;
}

int solver(vector<vector<int>>&cake,int x,int y,int**visited,int n){
    int sum=0;
    for(int k=0;k<4;k++){
        if(iseligible(cake,x+rowNbr[k],y+colNbr[k],visited,n)){
            visited[x+rowNbr[k]][y+colNbr[k]]=1;
            sum=sum+solver(cake,x+rowNbr[k],y+colNbr[k],visited,n);
        
        }
    }
    return 1+sum;
}


int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
     int **visited = new int *[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    int count=INT_MIN;
    int result=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (iseligible(cake,i,j,visited,n)) {
                visited[i][j]=1;
                result=solver(cake,i,j,visited,n);
                    
                count=max(result,count);
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}

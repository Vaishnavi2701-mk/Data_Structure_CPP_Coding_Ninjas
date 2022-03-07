/*Sudoku Solver
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0
6 0 0 0 5 0 0 4 0
0 2 0 4 0 0 0 1 0
2 0 8 0 0 0 0 0 0
0 7 0 5 0 9 0 6 0
0 0 0 0 0 0 4 0 1
0 1 0 0 0 5 0 8 0
0 9 0 0 7 0 0 0 4
0 8 2 0 4 0 0 0 6
Sample Output 1:
true*/

#include<bits/stdc++.h>
using namespace std;
bool check(int board[][9],int row,int col,int val){

for(int k=0;k<9;k++){
    if(board[row][k]==val){
        return false;
    }
    if(board[k][col]==val){
        return false;
    }
}

int rowFactor=row-(row%3);
int colFactor=col-(col%3);

for(int r=rowFactor;r<rowFactor+3;r++){
    for(int c=colFactor;c<colFactor+3;c++){
        if(board[r][c]==val){
            return false;
        }
    }
}
return true;
}
bool helper(int board[][9],int row,int col){

if(row==9){
    return true;
}
if(col==9){
    return helper(board,row+1,0);
}
if(board[row][col]!=0){
    return helper(board,row,col+1);
}

for(int k=1;k<=9;k++){
    if(check(board,row,col,k)){
        board[row][col]=k;
        if(helper(board,row,col+1)){
            return true;
        }
    }
     board[row][col]=0;
}
return false;
}

bool sudokuSolver(int board[][9]){
return helper(board,0,0);
}

int main(){

int board[9][9];
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cin>>board[i][j];
    }
}

if(sudokuSolver(board)){
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}

}

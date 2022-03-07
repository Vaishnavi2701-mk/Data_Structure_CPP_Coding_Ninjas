#include<iostream>
using namespace std;

int subsetsSumToK(int input[],int n,int output[][50],int k){

if(n==0){
    if(k==0){
        output[0][0]=0;
        return 1;
    }
    else{
        return 0;
    }
}
int output1=subsetsSumToK(input+1,n-1,output,k);
int output2=subsetsSumToK(input+1,n-1,output+output1,k-input[0]);
int smallOutputSize=output1+output2;
for(int i=output1;i<smallOutputSize;i++){
    for(int j=output[i][0];j>0;j--){
        output[i][j+1]=output[i][j];
    }
    output[i][1]=input[0];
    output[i][0]++;
}
return smallOutputSize;
}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;

  int size = subsetsSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

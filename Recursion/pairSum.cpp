#include<iostream>
using namespace std;

void helperFunction(int arr[],int s,int e){

if(s>=e){
    return;
}
int mid=(s+e)/2;
helperFunction(arr,0,mid);
helperFunction(arr,mid+1,e);
int output[e-s+1];
int i=0,j=mid+1,k=0;
while(i<=mid&&j<=e){
    if(arr[i]<arr[j]){
        output[k]=arr[i];
        k++;
        i++;
    }
    else{
        output[k]=arr[j];
        k++;
        j++;
    }
}
while(i<=mid){
    output[k]=arr[i];
    k++;
    i++;
}
while(j<=e){
    output[k]=arr[j];
    k++;
    j++;
}
for(int i=0;i<e;i++){
    arr[i]=output[i-s];
}
}

void mergeSort(int arr[],int n){
helperFunction(arr,0,n-1);
}

int pairSum (int arr[],int n,int num){
mergeSort(arr,n);
int i=0,j=n-1,count=0;
while(i<j){
if(arr[i]+arr[j]==num){
    count++;
    i++;
    j--;
}
else if(arr[i]+arr[j]>num){
    j--;
}
else if(arr[i]+arr[j]<num){
    i++;
}
}
return count;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}

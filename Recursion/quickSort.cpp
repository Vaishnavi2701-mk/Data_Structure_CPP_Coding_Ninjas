#include<iostream>
using namespace std;

void swap(int input[],int i,int j)/*(int *a,int *b) and receive it in pointer*/{
int temp=input[i];
input[i]=input[j];
input[j]=temp;
}

int partition(int input[], int l, int r){

int x=input[r];
int i=l-1;

for(int j=l;j<r/*j<=r-1*/;j++){

    if(input[j]<x){
        i++;
        swap(input,i,j);//swap(&input[i],&input[j])
    }
}
swap(input,i+1,r);//swap(&input[i+1],&input[e]) // basically it means we could directly pass the address ;
return i+1;

}

void helperFunction(int input[], int l,int r){
if(l<r){
    int pi=partition(input,l,r);
    helperFunction(input,l,pi-1);
    helperFunction(input,pi+1,r);
}


}


void quickSort(int input[],int size){
helperFunction(input,0,size-1);
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}



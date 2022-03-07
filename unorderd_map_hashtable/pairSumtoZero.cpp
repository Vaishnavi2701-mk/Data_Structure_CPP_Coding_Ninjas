#include <iostream>
using namespace std;
#include<unordered_map>
int pairSum(int *arr, int n) {
	unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    int count=0;

    for(int i=0;i<n;i++){
        count+=map[0-arr[i]];
        if(0-arr[i]==arr[i]){
            count--;
        }
    }
    return count/2;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}

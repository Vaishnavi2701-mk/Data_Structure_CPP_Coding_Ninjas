#include<iostream>
using namespace std;

int returnPermutations(string input,string output[]){

    if(input == "")
    {
        output[0] = "";
        return 1;
    }

    int smallOutput = returnPermutations(input.substr(1),output);
    string temp;
    for(int i=0;i<smallOutput;i++)
    {
        temp=output[i];
        for(int j=0;j<=temp.size();j++)
        {
            temp.insert(j,1,input[0]);
            output[j*smallOutput+i]=temp;
            temp.erase(j,1);
        }
    }
    return smallOutput*(output[0].size());
}



int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

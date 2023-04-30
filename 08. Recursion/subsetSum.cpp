#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int> arr, int index, vector<int> output, int givenSum){
    if(index == arr.size()){
        if(givenSum == 0){
            for(auto i: output){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        return;
    }
    
    subsetSum(arr, index+1, output, givenSum);
    
    output.push_back(arr[index]); 
    subsetSum(arr, index+1, output, givenSum - arr[index]);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    vector<int> output;

    subsetSum(arr,0,output,6);

    return 0;
}
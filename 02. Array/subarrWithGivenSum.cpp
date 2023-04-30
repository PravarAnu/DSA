#include <iostream>
#include <vector>
using namespace std;

bool subarrWithGivenSum(vector<int> &arr, int k){
    int s = 0;
    
    int sum = 0;
    
    for(int e = 0; e<arr.size(); e++){
        sum += arr[e];

        while(sum > k){
            sum -= arr[s];
            s++;
        }

        if(sum == k){
            return true;
        }
    }

    return false;
}

int main() {

    vector<int> arr = {1,4,20,3,10,5};
    int k = 33;
    cout<<subarrWithGivenSum(arr,k);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int longestEvenOddSubarr(vector<int> arr){
    int count = 1;
    int maxCount = 1;
    for(int i=1; i<arr.size(); i++){
        if((arr[i]%2 == 0 && arr[i-1]%2!=0) || (arr[i]%2 != 0 && arr[i-1]%2==0)){
            count ++;
            maxCount = max(maxCount, count);
        }
        else{
            count = 1;
        }
    }

    return maxCount;
}

int main() {

    vector<int> arr = {6,10,20,6,4,8};

    cout<<longestEvenOddSubarr(arr)<<endl;

    return 0;
}
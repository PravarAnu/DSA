#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrWithEqualZerosAndOnes(vector <int> &arr){
    unordered_map<int, int>m;
    int prefSum = 0;
    int longestSubarr = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0)
            prefSum += -1;
        else
            prefSum += arr[i];
        if(prefSum == 0){
            longestSubarr = i+1;
        }

        if(m.find(prefSum) == m.end()){
            m[prefSum] = i;
        }

        if(m.find(prefSum) != m.end()){
            longestSubarr = max(longestSubarr, i - m[prefSum]);
        }
    }

    return longestSubarr;
}

int main(){
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};

    cout<<longestSubarrWithEqualZerosAndOnes(arr);

    return 0;
}
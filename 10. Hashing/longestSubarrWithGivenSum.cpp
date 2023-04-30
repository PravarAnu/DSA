/*
    
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrWithGivenSum(vector<int> &arr, int givenSum){
    unordered_map<int, int> hash;
    
    int prefSum = 0;
    int longestSubarr = 0;
    for(int i=0; i<arr.size(); i++){
        prefSum += arr[i];

        if(prefSum == givenSum){
            longestSubarr = i+1;
        }
        if(hash.find(prefSum) == hash.end())
            hash[prefSum] = i;

        if(hash.find(prefSum-givenSum) != hash.end())
            longestSubarr = max(longestSubarr, i- hash[prefSum-givenSum]);
    }

    return longestSubarr;
}

int main(){
    vector<int> num = {1,0,1,0,1,1,1,1};
    int givenSum = 4;

    cout<<longestSubarrWithGivenSum(num, givenSum);

    return 0;
}
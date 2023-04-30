#include <iostream>
#include <vector>
using namespace std;

int equillibriumPointNaive(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        int lsum = 0;
        int rsum = 0;
        for(int j=0; j<i; j++){
            lsum += arr[j];
        }

        for(int k = i+1; k<arr.size(); k++){
            rsum += arr[k];
        }


        if(lsum == rsum){
            return i;
        }

    }

    return -1;
}


int equillibriumPointEfficient(vector<int> &arr){
    vector<int> prefixSum(arr.size());
    vector<int> suffixSum(arr.size());

    prefixSum[0] = arr[0];
    for(int i=1; i<arr.size();i++){
        prefixSum[i] += prefixSum[i-1] + arr[i];
    }

    suffixSum[suffixSum.size()-1] = arr[arr.size()-1];
    for(int i=arr.size()-2; i>=0; i--){
        suffixSum[i] += suffixSum[i+1] + arr[i];
    }

    for(int i=1; i<arr.size()-1; i++){
        if(prefixSum[i-1] == suffixSum[i+1]){
            return i;
        }
    }

    if(suffixSum[1] == 0){
        return 0;
    }

    if(prefixSum[arr.size()-2] == 0){
        return arr.size()-1;
    }

    return -1;
}


int equillibriumPointOptimized(vector<int> &arr){
    int rs = 0;
    int ls = 0;

    for(int i=0; i<arr.size();i++){
        rs += arr[i];
    }

    for(int i=0; i<arr.size(); i++){
        rs -= arr[i];

        if(rs == ls){
            return i;
        }

        ls += arr[i];
    }

    return -1;
}

int main() {

    vector<int> arr = {8,9,-9,-8,4};

    cout<<equillibriumPointNaive(arr)<<endl;
    cout<<equillibriumPointEfficient(arr)<<endl;
    cout<<equillibriumPointOptimized(arr)<<endl;

    return 0;
}
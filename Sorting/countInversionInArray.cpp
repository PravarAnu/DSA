#include <iostream>
#include <vector>
using namespace std;

int countAndMerge(vector<int> arr, int l, int mid, int r){
    
}

int countInversion(vector<int> arr, int l, int r){
    int res = 0;

    while(l<r){
        int mid = l+ (r-l)/2;
        res += countInversion(arr, l, mid);
        res += countInversion(arr, mid+1, r);

        res += countAndMerge(arr, l, mid, r);
    }

    return res;
}

int main() {

    vector<int> arr = {2,5,8,11,3,6,9,13};

    cout<<countInversion(arr, 0, arr.size());

    return 0;
}
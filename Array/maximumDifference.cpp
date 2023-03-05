#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumDifference(vector<int> &arr){
    int mini = INT_MAX;
    int ans = INT_MIN;
    for(auto i:arr){
        mini = min(mini, i);
        
        ans = max(ans, (i-mini));
    }

    return ans;
}

int main() {

    vector<int> arr = {2,3,10,6,4,8,1};

    cout<<maximumDifference(arr)<<endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int oneOddOccurring(vector<int> arr){
    int ans = 0;

    for(auto i: arr){
        ans ^= i;
    }

    return ans;
}

int main() {

    vector<int> arr = {2,3,4,1,2,1,4,6,5,5,6};

    cout<<oneOddOccurring(arr)<<endl;

    return 0;
}
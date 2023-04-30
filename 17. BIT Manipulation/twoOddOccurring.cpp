#include <iostream>
#include <vector>
using namespace std;

pair<int,int> oneOddOccurring(vector<int> arr){
    int ans = 0;
    int res1 = 0;
    int res2 = 0;

    for(auto i: arr){
        ans ^= i;
    }

    int diff = ans & ~(ans-1);
    for(auto i: arr){
        if((i&diff) != 0){
            res1 ^= i;
        }else{
            res2 ^= i;
        }
    }

    return {res1, res2};
}

int main() {

    vector<int> arr = {2,3,4,3,2,1,4,6,5,5,6,7};

    pair<int,int> ans = oneOddOccurring(arr);
    
    cout<<ans.first<<' '<<ans.second<<endl;

    return 0;
}
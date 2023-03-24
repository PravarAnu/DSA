#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> intervals){
    vector<pair<int,int>> ans;

    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);

    for(int i=1; i<intervals.size(); i++){
        if(intervals[i].first >= ans[ans.size()-1].first && intervals[i].first <= ans[ans.size()-1].second){
            ans[ans.size()-1].first = min(ans[ans.size()-1].first, intervals[i].first);
            ans[ans.size()-1].second = max(ans[ans.size()-1].second, intervals[i].second);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}


int main() {

    vector<pair<int,int>> intervals = {{3,4}, {5,7}, {1,2}, {6,8}};

    vector<pair<int,int>> ans = mergeIntervals(intervals);

    for(auto i: ans){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}
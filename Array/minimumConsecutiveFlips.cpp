#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> minimumFlipsNaive(vector<int> &arr) {
    vector<pair<int, int>> ans1;
    vector<pair<int, int>> ans2;

    int count = 0;
    int j;
    for (j = 0; j < arr.size(); j++) {
        if (arr[j] == 0) {
            count++;
        } else {
            if (count > 0) {
                ans1.push_back({j - count, j - 1});
                count = 0;
            }
        }
    }

    if (count > 0) {
        ans1.push_back({j - count, j - 1});
        count = 0;
    }

    count = 0;

    for (j = 0; j < arr.size(); j++) {
        if (arr[j] == 1) {
            count++;
        } else {
            if (count > 0) {
                ans2.push_back({j - count, j - 1});
                count = 0;
            }
        }
    }
    if (count > 0) {
        ans2.push_back({j - count, j - 1});
        count = 0;
    }

    if(ans1.size() == 0){
        return ans2;
    }

    if(ans2.size() == 0){
        return ans1;
    }


    if (ans1.size() > ans2.size()) {
        return ans2;
    }

    return ans1;
}

int main() {

    vector<int> arr = {0,1, 1, 1, 1,0};

    vector<pair<int, int>> ans = minimumFlipsNaive(arr);

    for (auto i : ans) {
        cout << i.first << " - " << i.second << endl;
    }

    return 0;
}
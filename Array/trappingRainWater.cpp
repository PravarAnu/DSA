#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int trappingRainWaterNaive(vector<int> blocks) {
    int totalWaterTrapped = 0;

    for (int i = 1; i < blocks.size() - 1; i++) {
        int maxLeft = blocks[i];

        for (int j = 0; j < i; j++) {
            maxLeft = max(maxLeft, blocks[j]);
        }

        int maxRight = blocks[i];
        for (int j = i + 1; j < blocks.size(); j++) {
            maxRight = max(maxRight, blocks[j]);
        }

        totalWaterTrapped += (min(maxLeft, maxRight) - blocks[i]);
    }

    return totalWaterTrapped;
}

int trappingRainWaterEfficient(vector<int> blocks) {
    int totalWaterTrapped = 0;


    vector<int> maxLeft(blocks.size());
    maxLeft[0] = blocks[0];

    for (int i = 1; i < maxLeft.size(); i++) {
        maxLeft[i] = max(blocks[i], maxLeft[i - 1]);
    }

    vector<int> maxRight(blocks.size());

    maxRight[maxRight.size()-1] = blocks[blocks.size()-1];

    for (int i = maxRight.size()-2; i >= 0; i--) {
        maxRight[i] = max(blocks[i], maxRight[i + 1]);
    }

    for (int i = 1; i < blocks.size() - 1; i++) {
        totalWaterTrapped += (min(maxLeft[i], maxRight[i]) - blocks[i]);
    }

    return totalWaterTrapped;
}

int main() {

    vector<int> blocks = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trappingRainWaterNaive(blocks)<<endl;
    
    cout << trappingRainWaterEfficient(blocks)<<endl;


    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int buyAndSellStockOnce(vector<int> &stockPrices){
    int minStockPrice = INT_MAX;
    int maxProfit = 0;

    for(int i=0; i<stockPrices.size(); i++){
        int profitOfTheDay = stockPrices[i] - minStockPrice;

        maxProfit = max(profitOfTheDay, maxProfit);
        minStockPrice = min(minStockPrice, stockPrices[i]);
    }

    return maxProfit;
}

int main() {

    vector<int> stockPrices = {7,6,4,3,1};

    cout<<buyAndSellStockOnce(stockPrices);

    return 0;
}
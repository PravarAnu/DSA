#include <iostream>
#include <vector>
using namespace std;

int buyAndSellStocks(vector<int> stocksPrice) {
    int totalProfit = 0;

    for (int i = 1; i < stocksPrice.size(); i++) {
        if (stocksPrice[i] > stocksPrice[i - 1]) {
            totalProfit += (stocksPrice[i] - stocksPrice[i - 1]);
        }
    }

    return totalProfit;
}

int main() {

    vector<int> stocksPrice = {7, 6, 4, 3, 1};

    cout << buyAndSellStocks(stocksPrice);

    return 0;
}
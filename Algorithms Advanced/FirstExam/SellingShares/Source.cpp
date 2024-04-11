#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> buy(n, 0), sell(n, 0);

    buy[0] = -prices[0];
    for (int i = 1; i < n; i++) {
        buy[i] = std::max(buy[i - 1], -prices[i]);
    }

    sell[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sell[i] = std::max(sell[i + 1], prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        maxProfit = std::max(maxProfit, sell[i] + buy[i]);
    }

    return maxProfit;
}

void findDays(const std::vector<int>& prices, int maxProfit) {
    int n = prices.size();
    std::vector<int> buy(n, 0), sell(n, 0);

    buy[0] = -prices[0];
    for (int i = 1; i < n; i++) {
        buy[i] = std::max(buy[i - 1], -prices[i]);
    }

    sell[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sell[i] = std::max(sell[i + 1], prices[i]);
    }

    int profit = 0;
    for (int i = 0; i < n; i++) {
        if (sell[i] + buy[i] == maxProfit) {
            profit = sell[i] + buy[i];
            std::cout << "Buy on day " << i + 1 << " and sell on day " << i + 1 << std::endl;
            break;
        }
    }
}

int main() {
    std::vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    int maxProf = maxProfit(prices);
    std::cout << "Maximum profit: " << maxProfit << std::endl;

    findDays(prices, maxProf);

    return 0;
}

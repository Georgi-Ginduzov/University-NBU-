#include <iostream>
#include <vector>

int numberOfWays(int n, int m, int x) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(x + 1, 0));

    for (int s = 1; s <= m; s++) {
        dp[1][s] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int s = 1; s <= x; s++) {
            for (int j = 1; j <= m; j++) {
                if (s >= j) {
                    dp[i][s] += dp[i - 1][s - j];
                }
            }
        }
    }

    return dp[n][x];
}

int main() {
    int n, m, x;
    std::cin >> n >> m >> x;
    int ways = numberOfWays(n, m, x);
    std::cout << "Number of ways: " << ways << std::endl;
    return 0;
}

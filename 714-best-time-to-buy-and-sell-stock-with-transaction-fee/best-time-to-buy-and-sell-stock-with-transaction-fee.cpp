class Solution {
public:
    int dp[50001][2]; // Memoization table

    int solve(vector<int>& prices, int i, bool holding, int fee) {
        if (i == prices.size()) return 0;
        if (dp[i][holding] != -1) return dp[i][holding];

        int profit = 0;
        if (holding) {
            // Choice: sell or hold
            profit = max(
                prices[i] - fee + solve(prices, i + 1, 0, fee),  // Sell
                solve(prices, i + 1, 1, fee)                     // Hold
            );
        } else {
            // Choice: buy or skip
            profit = max(
                -prices[i] + solve(prices, i + 1, 1, fee),      // Buy
                solve(prices, i + 1, 0, fee)                    // Skip
            );
        }

        return dp[i][holding] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, fee); // Start from day 0, not holding stock
    }
};

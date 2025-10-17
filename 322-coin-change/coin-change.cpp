class Solution {
public:
    int makeAmount(int n, vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(n == 0) return INT_MAX-1;

        if(amount >= coins[n-1]) {
            int inc = 1 + makeAmount(n, coins, amount-coins[n-1]);

            int exc = makeAmount(n-1, coins, amount);

            return min(inc, exc);
        }
        
        int exc = makeAmount(n-1, coins, amount);
        return exc;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int j = 1; j < amount+1; j++) {
            dp[0][j] = INT_MAX-1;
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < amount+1; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }   
        }
        
        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
};
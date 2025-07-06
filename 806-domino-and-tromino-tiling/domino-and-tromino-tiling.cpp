class Solution {
public:
    int numTilings(int n) {
        int MOD = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> pre(n + 1); // prefix sum for dp

        dp[0] = 1;
        dp[1] = 1;
        pre[0] = 1;
        pre[1] = 2;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            if (i >= 3) {
                dp[i] = (dp[i] + 2 * pre[i - 3]) % MOD;
            }
            pre[i] = (pre[i - 1] + dp[i]) % MOD;
        }

        return dp[n];
    }
};

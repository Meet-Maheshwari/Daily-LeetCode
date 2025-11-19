class Solution {
public:
    bool solve(string& t, string& p, int n, int m, vector<vector<int>>& dp) {
        if(n == 0 && m == 0) return dp[n][m] = 1;
        if(m == 0) return dp[n][m] = 0;
        if(n == 0) {    
            for(int i = 0; i < m; i++) {
                if(p[i] != '*') return dp[n][m] = 0; 
            }
            return dp[n][m] = 1;
        } 

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(p[m-1] == '*') {
            bool match = solve(t, p, n, m-1, dp);
            bool nomatch = solve(t, p, n-1, m, dp);
            dp[n][m] = match || nomatch;

        } else if(p[m-1] == '?') {
            dp[n][m] = solve(t, p, n-1, m-1, dp);
        } else if(p[m-1] == t[n-1]) {
            dp[n][m] = solve(t, p, n-1, m-1, dp);
        } else {
            dp[n][m] = 0;
        }

        return dp[n][m];
    }

    bool isMatch(string t, string p) {
        int n = t.size();
        int m = p.size();
        vector<vector<int>> dp (n+1, vector<int>(m+1, -1));

        solve(t, p, n, m, dp);
        return dp[n][m];
    }
};
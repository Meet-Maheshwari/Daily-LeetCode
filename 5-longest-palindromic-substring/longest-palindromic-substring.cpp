class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string& str, int st, int end) {
        if(st >= end) {
            return 1;
        }
        if(dp[st][end] != -1) {
            return dp[st][end];
        }

        if(str[st] == str[end]) {
            return dp[st][end] = isPalindrome(str, st+1, end-1);
        }

        return dp[st][end] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0, start = 0;
        dp.assign(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j)) {
                    int len = j-i+1;
                    if(maxLength < len) {
                        maxLength = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
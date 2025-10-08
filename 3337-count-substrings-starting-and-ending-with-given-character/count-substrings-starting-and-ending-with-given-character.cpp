class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long lastS = 0;
        long long count = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                count += lastS + 1;
                lastS++;
            }
        }

        return count;
    }
};
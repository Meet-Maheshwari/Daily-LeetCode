class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n == 0) return 0;

        unordered_map<int, int> frequency;

        for(int i = 0; i < n; i++) {
            frequency[s[i]-'a']++;
        }

        int breakPoint = -1;
        for(auto freq : frequency) {
            if(freq.second < k) {
                breakPoint = freq.first;
                break;
            }
        }

        if(breakPoint != -1) {
            string left = "", right = "";
            char ch = breakPoint+'a';

            for(int i = 0; i < n; i++) {
                if(s[i] == ch) {
                    left = s.substr(0, i);
                    right = s.substr(i+1);

                    int longestLeft = longestSubstring(left, k);
                    int longestRight = longestSubstring(right, k);
                    return max(longestLeft, longestRight);
                }
            }
        }

        return n;
    }
};
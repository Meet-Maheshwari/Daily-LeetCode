class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        int l = 0, r = 0, maxLen = 0;

        while(r < n) {
            char ch = s[r];

            if(!map.count(ch)) {
                map[ch] = r;
            } else {
                l = max(map[ch] + 1, l);
                map[ch] = r;
            }

            int len = r - l + 1;
            maxLen = max(len, maxLen);
            r++;
        }
        return maxLen;
    }
};
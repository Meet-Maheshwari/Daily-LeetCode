class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxFreq = 0, maxLen = 0;
        unordered_map<int, int> hash(26);

        while(r < s.size()) {
            hash[s[r] - 'A']++;
            maxFreq = max(hash[s[r]-'A'], maxFreq);

            if((r-l+1)-maxFreq > k) {
                hash[s[l]-'A']--;
                maxFreq = 0;
                for(int i = 0; i < 26; i++) {
                    maxFreq = max(hash[i], maxFreq);
                }
                l++;
            }

            if((r-l+1)-maxFreq <= k) {
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }
        

        return maxLen;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            lastSeen[ch] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                ans = ans + min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1;
            }
        }

        return ans;
    }
};

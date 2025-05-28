class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int ans = 0;

        for(int i = s.size()-1; i >= 0; i--) {
            int ch = s[i] - 'a';
            lastSeen[ch] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                ans = ans + (s.size() - max(lastSeen[0], max(lastSeen[1], lastSeen[2])));
            }
        }

        return ans;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, cnt = 0, sIdx = -1, n = t.size(), minLen = INT_MAX;
        unordered_map<int, int> map;

        for(int el : t) {
            map[el]++;
        }

        while(r < s.size()) {
            if(map[s[r]] > 0) {
                cnt++;
            } 
            map[s[r]]--;

            while(cnt == n) {
                if((r-l+1) < minLen) {
                    minLen = (r-l+1);
                    sIdx = l;
                }
                map[s[l]]++;
                if(map[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};
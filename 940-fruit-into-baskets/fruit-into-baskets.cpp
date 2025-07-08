class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, n = fruits.size(), len = 0, maxLen = INT_MIN;
        unordered_map<int, int> map;

        while(r < n) {
            if(!map.count(fruits[r])) {
                map[fruits[r]] = 1;
            } else {
                map[fruits[r]]++;
            }

            if(map.size() > 2) {
                map[fruits[l]]--;
                if(map[fruits[l]] == 0) {
                    map.erase(fruits[l]);
                }
                l++;
            }

            if(map.size() <= 2) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }

        return maxLen;
    }
};
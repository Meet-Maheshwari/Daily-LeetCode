class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        int maxLen = 0;

        unordered_map<int, int> hash ;//fruit, count;

        while(r < fruits.size()) {
            int fruit = fruits[r];

            if(hash.count(fruit)) {
                hash[fruit]++;
            } else {
                hash[fruit] = 1;
            }
            while(hash.size() > 2) {
                hash[fruits[l]]--;
                if(hash[fruits[l]] == 0) hash.erase(fruits[l]);
                l++;
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }

        return maxLen;
    }
};
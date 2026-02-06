class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        int n = numbers.size();
        vector<int> ans(2);

        for(int i = 0; i < n; i++) {
            if(map.count(target - numbers[i])) {
                ans[0] = map[target - numbers[i]] + 1;
                ans[1] = i+1;
                break;
            } else {
                map[numbers[i]] = i;
            }
        }

        return ans;
    }
};
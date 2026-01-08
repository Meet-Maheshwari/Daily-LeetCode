class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; //sum, idx
        int n = nums.size();

        vector<int> ans = {0, 0};
        for(int i = 0; i < n; i++) {
            if(map.count(target - nums[i]) == 0) {
                map[nums[i]] = i;
            } else {
                ans = {map[target-nums[i]], i};  
                break; 
            }
        }
        return ans;
    }
};
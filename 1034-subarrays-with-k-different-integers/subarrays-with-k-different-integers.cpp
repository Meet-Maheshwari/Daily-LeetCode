class Solution {
public:
    int countSubArraysWithDistinct(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int l = 0, r = 0, cnt = 0, n = nums.size();
        unordered_map<int, int> map;

        while(r < n) {
            int num = nums[r];
            if(!map.count(num)) {
                map[num] = 1;
            } else {
                map[num]++;
            }

            while(map.size() > k) {
                map[nums[l]]--;
                if(map[nums[l]] == 0) map.erase(nums[l]);
                l++; 
            }

            if(map.size() <= k) cnt = cnt + (r - l + 1);
            r++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = countSubArraysWithDistinct(nums, k);
        int ans2 = countSubArraysWithDistinct(nums, k-1);

        return ans1 - ans2;
    }
};
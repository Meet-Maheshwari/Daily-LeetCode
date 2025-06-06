class Solution {
public:
    int robHelper(vector<int> nums) {
        int n = nums.size();
       int prev1 = nums[0], prev2 = 0;

        for(int i = 1; i < n; i++) {
            //pick
            int rob = nums[i] + prev2;

            //Don't pick
            int noRob = 0 + prev1;

            prev2 = prev1;
            prev1 = max(rob, noRob);

        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> nums1, nums2;

        for(int i = 0; i < n; i++) {
            if(i != 0) nums1.push_back(nums[i]);
            if(i != n-1) nums2.push_back(nums[i]);
        }

        int ans1 = robHelper(nums1);
        int ans2 = robHelper(nums2);

        return max(ans1, ans2);
    }
};
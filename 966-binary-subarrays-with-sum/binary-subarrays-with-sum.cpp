class Solution {
public:
    int subArraysWithGoal(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int l = 0, r = 0, cnt = 0, sum = 0;

        while(r < nums.size()) {
            sum += nums[r];

            while(sum > goal) {
                sum = sum - nums[l];
                l++;
            }

            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans1 = subArraysWithGoal(nums, goal);
        int ans2 = subArraysWithGoal(nums, goal-1); 

        return ans1 - ans2;       
    }
};
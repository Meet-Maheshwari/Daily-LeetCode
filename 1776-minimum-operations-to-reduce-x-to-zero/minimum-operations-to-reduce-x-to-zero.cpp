class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, r = 0, sum = 0, maxLen = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum == x) return nums.size();
        int target = totalSum - x;

        while(r < nums.size()) {
            sum += nums[r];

            while(l < r && sum > target) {
                sum -= nums[l];
                l++;
            }

            if(sum == target) {
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }

        return maxLen == 0 ? -1 : nums.size()-maxLen;
    }
};

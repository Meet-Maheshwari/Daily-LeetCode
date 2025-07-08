class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), len = 0, maxLen = INT_MIN, zeros = 0;

        while(r < n) {
            if(nums[r] == 0) {
                zeros++;
            }

            if(zeros > 1) {
                if(nums[l] == 0) zeros--;
                l++;
            }

            if(zeros <= 1) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen-1;
    }
};
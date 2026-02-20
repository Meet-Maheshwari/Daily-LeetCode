class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long sum = 0, maxi = 0;

        unordered_map<int, int> mmap;

        while(r < k) {
            sum += nums[r];
            mmap[nums[r]]++;
            if(mmap.size() == k) {
                maxi = max(sum, maxi);
            }
            r++;
        }
        if(r == n) return maxi;
        sum -= nums[l];
        mmap[nums[l]]--;
        if(mmap[nums[l]] == 0) mmap.erase(nums[l]);
        l++;

        while(r < n) {
            sum += nums[r];
            mmap[nums[r]]++;
            if(mmap.size() == k) {
                maxi = max(sum, maxi);
            }
            sum -= nums[l];
            mmap[nums[l]]--;
            if(mmap[nums[l]] == 0) {
                mmap.erase(nums[l]);
            }
            l++;
            r++;
        }

        return maxi;
    }
};
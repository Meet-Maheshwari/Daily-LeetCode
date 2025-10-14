class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long closest = nums[0] + nums[1] + nums[n-1];

        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int p = i+1, q = n-1;

            while(p < q) {
                long long sum = (long long)nums[i] + nums[p] + nums[q];
                if(abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if(sum > target) {
                    q--;
                } else if(sum < target) {
                    p++;
                } else {
                    return sum;
                }
            }
        }

        return (int)closest;
    }
};
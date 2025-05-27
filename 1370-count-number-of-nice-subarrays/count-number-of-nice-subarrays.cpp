class Solution {
public:
    int numberOfNiceArrays(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int l = 0, r = 0, cnt = 0, sum = 0;

        while(r < nums.size()) {
            sum += nums[r];

            while(sum > k) {
                sum -= nums[l];
                l++;
            }

            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }

        int ans1 = numberOfNiceArrays(nums, k);
        int ans2 = numberOfNiceArrays(nums, k-1);

        return ans1 - ans2;
    }
};
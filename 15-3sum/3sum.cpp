class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int p = i+1;
            int q = n-1;

            while(p < q) {
                int sum = nums[i] + nums[p] + nums[q];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[p], nums[q]});
                    p++; q--;

                    while(p < q && nums[p] == nums[p-1]) p++;
                } else if(sum < 0) {
                    p++;
                } else {
                    q--;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int p = i+1, q = n-1;
            while(p < q) {
                if((nums[i] + nums[p]) + nums[q] == 0) {
                    ans.push_back({nums[i], nums[p], nums[q]});
                    p++; q--;                    
                    while(p < q && nums[p] == nums[p-1]) p++;
                    while(p < q && nums[q] == nums[q+1]) q--;
                } else if((nums[i] + nums[p]) + nums[q] < 0) {
                    p++;
                } else {
                    q--;
                }
            }
        }
        return ans;
    }
};
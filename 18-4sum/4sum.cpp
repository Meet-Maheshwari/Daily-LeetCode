class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; ) {
                int p = j+1, q = n-1;

                while(p < q) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[p] + nums[q];

                    if(sum > target) {
                        q--;
                    } else if(sum < target) {
                        p++;
                    } else{
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;

                        while(p < q && nums[q] == nums[q+1]) q--;
                    }
                }

                ++j;
                while(j < n-2 && nums[j] == nums[j-1]) j++;
            }
        }

        return ans;
    }
};
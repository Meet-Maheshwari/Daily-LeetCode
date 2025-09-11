class Solution {
public:
    set<vector<int>> s;

    void findSubsets(int i, vector<vector<int>>& ans, vector<int>& subsets, vector<int>& nums, int n) {
        if(i == n) {
            if(s.find(subsets) == s.end()) {
                s.insert(subsets);
                ans.push_back(subsets);
            }
            return;
        }

        //include
        subsets.push_back(nums[i]);
        findSubsets(i+1, ans, subsets, nums, n);
        subsets.pop_back();
        //exclude;
        findSubsets(i+1, ans, subsets, nums, n);
    } 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subsets;

        findSubsets(0, ans, subsets, nums, n);
        return ans;
    }
};
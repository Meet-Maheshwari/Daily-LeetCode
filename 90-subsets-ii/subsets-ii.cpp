class Solution {
public:
    vector<vector<int>> mat;

    void rec(vector<int>& nums, vector<int>& output, int idx) {
        if(idx == nums.size()) {
            mat.push_back(output);
            return;
        }

        // YES choice
        output.push_back(nums[idx]);
        rec(nums, output, idx + 1);
        output.pop_back(); // backtracking

        // ❌ DUPLICATE ISSUE FIXED HERE
        // skip all duplicates
        int nextIdx = idx + 1;
        while(nextIdx < nums.size() && nums[nextIdx] == nums[idx]) {
            nextIdx++;
        }

        // NO choice
        rec(nums, output, nextIdx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // ❌ REQUIRED to handle duplicates
        vector<int> output;
        rec(nums, output, 0);
        return mat;
    }
};
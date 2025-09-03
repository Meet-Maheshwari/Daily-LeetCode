class Solution {
public:
    set<vector<int>> s;

    void findCombinations(int n, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combs) {   
        if(n == 0 || target < 0) {
            return;
        }    

        if(target == 0) {
            if(s.find(combs) == s.end()) {
                s.insert(combs);
                ans.push_back(combs);
            }
            return;
        }

        if(candidates[n-1] <= target) {
            findCombinations(n-1, candidates, target, ans, combs);
            combs.push_back(candidates[n-1]);
            findCombinations(n, candidates, target-candidates[n-1], ans, combs);
            combs.pop_back();
        } else {
            findCombinations(n-1, candidates, target, ans, combs);
        }
    }
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combs;

        int n = candidates.size();
        findCombinations(n, candidates, target, ans, combs);
        return ans;
    }
};
class Solution {
public:
    set<vector<int>>s;

    void findCombinations(int i, int n, vector<int>& comb, vector<vector<int>>& ans, vector<int>& candidates, int target) { 
        if(target == 0) {
            if(s.find(comb) == s.end()) {
                s.insert(comb);
                ans.push_back(comb);
            }
            return;
        }
        if(i >= n) {
            return;
        }

        if(target - candidates[i] >= 0) {
            comb.push_back(candidates[i]);
            findCombinations(i+1, n, comb, ans, candidates, target - candidates[i]);
            comb.pop_back();
            int idx = i;
            while(idx < n && candidates[idx] == candidates[i]) idx++;
            findCombinations(idx, n, comb, ans, candidates, target);    
        } else {
            int idx = i;
            while(idx < n && candidates[idx] == candidates[i]) idx++;
            findCombinations(idx, n, comb, ans, candidates, target);    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        int n = candidates.size();
        findCombinations(0, n, combination, ans, candidates, target);

        return ans;
    }
};
class Solution {
public:
    void getCombinations(int i, int size, int n, int k, vector<int>& comb, vector<vector<int>>& ans) {
        if(size == k) {
            ans.push_back(comb);
            return;
        }
        if(i > n) return;

        for(int idx = i; idx <= n; idx++) {
            comb.push_back(idx);
            getCombinations(idx+1, size+1, n, k, comb, ans);
            comb.pop_back();
        }  
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;

        getCombinations(1, 0, n, k, comb, ans);
        return ans;
    }
};
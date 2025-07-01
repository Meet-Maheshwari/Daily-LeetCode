class Solution {
public:
    void calculateComb(int start, int n, int k, vector<int>& path, vector<vector<int>>& result) {
        if(k == 0 && n == 0) {
            result.push_back(path);
            return;
        }

        if(k < 0 || n < 0) {
            return;
        }

        for(int i = start; i <= 9; i++) {
            path.push_back(i);
            calculateComb(i+1, n-i, k-1, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int>path;

        calculateComb(1, n, k, path, result);
        return result;
    }
};
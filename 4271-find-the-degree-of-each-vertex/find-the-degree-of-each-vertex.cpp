class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j]) {
                    indegree[i]++;
                    indegree[j]++;
                    matrix[j][i] = 0;
                }
            }
        }

        return indegree;
    }
};
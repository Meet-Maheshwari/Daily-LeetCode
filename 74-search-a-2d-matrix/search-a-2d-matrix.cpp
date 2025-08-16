class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = 0;
        while(i < m && j < n) {
            if(matrix[i][j] == target) return true;
            else if(i+1 < m && target >= matrix[i+1][j]) {
                i++;
            } else {
                j++;
            }
        }

        return false;
    }
};
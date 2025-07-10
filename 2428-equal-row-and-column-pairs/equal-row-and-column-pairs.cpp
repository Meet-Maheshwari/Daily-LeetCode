class Solution {
public:
    int equalPairs(vector<vector<int>>& grid1) {
       int n = grid1.size(), m = grid1[0].size();
        vector<vector<int>> grid2(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid2[i][j] = grid1[j][i];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid1[i] == grid2[j]) ans++;
            }
        }

        return ans;
    }
};
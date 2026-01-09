class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long s1 = 0, s2 = 0, n = grid.size();
        long long sum1 = 0, sum2 = 0;
        
        for(int i = 1; i <= n*n; i++){
            s1 += i;
            sum1 += i*i;
        } 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s2 += grid[i][j];
                sum2 += grid[i][j] * grid[i][j];
            }
        }

        long long val1 = s2 - s1;
        long long val2 = sum2 - sum1;

        val2 = val2 / val1;
        int x = (int)(val2 + val1)/2;

        int y = x-val1;

        return {x, y};
    }
};
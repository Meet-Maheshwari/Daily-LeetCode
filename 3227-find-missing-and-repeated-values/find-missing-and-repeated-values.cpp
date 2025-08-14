class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() * grid[0].size();
        long long s = (1LL * n * (n+1)) / 2;
        long long s2 = (1LL * n * (n+1) * (2LL *n+1))/ 6;

        long long sn = 0, s2n = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                sn += grid[i][j];
                s2n += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }

        long long val1 = sn - s;
        long long val2 = s2n - s2;

        val2 = val2/val1;
        long long x = (val2 + val1)/ 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};
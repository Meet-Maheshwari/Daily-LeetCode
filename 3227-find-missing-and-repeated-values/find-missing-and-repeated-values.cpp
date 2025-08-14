class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> freq((n*n)+1, -1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int el = grid[i][j];
                freq[el]++;
            }
        }

        vector<int> result(2);
        for(int i = 1; i < freq.size(); i++) {
            if(freq[i] == 1) result[0] = i;
            if(freq[i] == -1) result[1] = i;
        }

        return result;
    }
};
class Solution {
public:
    unordered_map<int, int> mp;

    bool solve(vector<int>& stones, int cur_stone_idx, int prev_jump, vector<vector<int>>& dp) {
        if(cur_stone_idx == stones.size()-1) {
            return dp[cur_stone_idx][prev_jump] = true;
        }

        if(dp[cur_stone_idx][prev_jump] != -1) {
            return dp[cur_stone_idx][prev_jump];
        }

        bool result = false;
        for(int next_jump = prev_jump-1; next_jump <= prev_jump+1; next_jump++) {
            if(next_jump > 0) {
                int next_stone = stones[cur_stone_idx] + next_jump; 
                if(mp.count(next_stone)) {
                    result = result || solve(stones, mp[next_stone], next_jump, dp);
                }
            }
        }

        return dp[cur_stone_idx][prev_jump] = result;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        vector<vector<int>> dp(2001, vector<int>(2001, -1));

        return solve(stones, 0, 0, dp);
    }
};
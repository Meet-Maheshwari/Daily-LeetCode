class Solution {
public:
    // Helper function with memoization to calculate min cost starting from step i
    int minCostHelper(vector<int>& cost, int i, vector<int>& memo) {
        // If we are at or beyond the top (step size n), no more cost is needed
        if (i >= cost.size()) {
            return 0;
        }

        // If already computed, return the stored result
        if (memo[i] != -1) {
            return memo[i];
        }

        // Recursively calculate the cost of stepping 1 stair or 2 stairs
        int oneStep = cost[i] + minCostHelper(cost, i + 1, memo);
        int twoStep = cost[i] + minCostHelper(cost, i + 2, memo);

        // Store and return the minimum cost of the two options
        return memo[i] = min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);

        // We can start at step 0 or step 1
        return min(minCostHelper(cost, 0, memo), minCostHelper(cost, 1, memo));
    }
};

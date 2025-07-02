class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long ans = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p2;

        for (int i = 0; i < candidates && left <= right; ++i)
            p1.emplace(costs[left], left++);

        for (int i = 0; i < candidates && left <= right; ++i)
            p2.emplace(costs[right], right--);

        for (int i = 0; i < k; ++i) {
            if (!p1.empty() && (!p2.empty() && p1.top().first <= p2.top().first || p2.empty())) {
                ans += p1.top().first;
                p1.pop();
                if (left <= right)
                    p1.emplace(costs[left], left++);
            } else {
                ans += p2.top().first;
                p2.pop();
                if (left <= right)
                    p2.emplace(costs[right], right--);
            }
        }

        return ans;
    }
};

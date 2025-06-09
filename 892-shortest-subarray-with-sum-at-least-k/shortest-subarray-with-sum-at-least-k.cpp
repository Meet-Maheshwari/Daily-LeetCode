class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, int>> prefixSum;
        long long sum = 0;
        int r = 0, n = nums.size(), minLen = INT_MAX;

        while(r < n) {
            sum += nums[r];

            if(sum >= k) {
                minLen = min(minLen, r+1);
            }

            while(!prefixSum.empty() && (sum - prefixSum.front().first >= k)) {
                minLen = min(minLen, r-prefixSum.front().second);
                prefixSum.pop_front();
            }
            while(!prefixSum.empty() && prefixSum.back().first >= sum) {
                prefixSum.pop_back();
            }
            prefixSum.push_back(make_pair(sum, r));
            r++;
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};

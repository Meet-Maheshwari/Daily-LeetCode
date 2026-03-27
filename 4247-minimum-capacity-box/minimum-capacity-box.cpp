class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int minCapIdx = n, minCap = INT_MAX;

        for(int i = 0; i < n; i++) {

            if(capacity[i] >= itemSize) {
                if(capacity[i] < minCap) {
                    if(capacity[i] == minCap) {
                        continue;
                    } else {
                        minCapIdx = i;
                        minCap = capacity[i];
                    }
                }
            }
        }

        return minCapIdx == n ? -1 : minCapIdx;
    }
};
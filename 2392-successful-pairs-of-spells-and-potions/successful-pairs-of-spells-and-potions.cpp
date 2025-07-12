class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());

        for(int i = 0; i < n; i++) {
            int st = 0, end = m-1, pos = m;
            while(st <= end) {
                int mid = st + (end-st)/2;

                if((long long)spells[i] * potions[mid] >= success) {
                    pos = mid;
                    end = mid - 1;
                } else {
                    st = mid+1;
                }
            }
            ans[i] = m-pos;
        }

        return ans;
    }
};
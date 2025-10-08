class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> pairs(n, 0);

        sort(potions.begin(), potions.end());

        for(int i = 0; i < n; i++) {
            int spell = spells[i];

            int l = 0, r = m-1;
            while(l <= r) {
                int mid = l + (r-l)/2;
                int potion = potions[mid];
                if((long long)potion * spell >= success) {
                    if(mid - 1 >= 0 && (long long)potions[mid-1]* spell >= success){
                        r = mid - 1;
                    } else {
                        pairs[i] = m - mid;
                        break;
                    }
                } else if(potions[mid] > success) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return pairs;
    }
};
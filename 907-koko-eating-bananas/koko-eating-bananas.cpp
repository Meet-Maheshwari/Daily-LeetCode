class Solution {
public:
    bool kokoCanEatMid(long long mid, vector<int>& piles, int h) {
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + mid - 1) / mid; 
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long si = 1;
        long long ei = *max_element(piles.begin(), piles.end());
        int ans = ei;

        while(si <= ei) {
            long long mid = si + (ei - si)/2;

            if(kokoCanEatMid(mid, piles, h)) {
                ei = mid-1;
                ans = mid;
            } else {
                si = mid+1;
            }
        }

        return ans;
    }
};
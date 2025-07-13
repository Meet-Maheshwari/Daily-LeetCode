class Solution {
public:
    bool canEatAll(vector<int>& piles, int k, int h) {
        long long hours = 0;

        for(int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1;
        long long end = *max_element(piles.begin(), piles.end());
        long long k = end;

        while(start <= end) {
            long long mid = start + (end-start)/2;

            if(canEatAll(piles, mid, h)) {
                end = mid-1;
                k = mid;
            } else {
                start = mid+1;
            }
        }

        return (int)k;
    }
};
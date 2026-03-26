class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;
        int n = nums1.size();

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 != 0) {
                smallestOdd = min(smallestOdd, nums1[i]);
            }
        }

        if(smallestOdd == INT_MAX) return true;

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 == 0) {
                if(nums1[i] - smallestOdd < 1) return false; 
            }
        }

        return true;
    }
};
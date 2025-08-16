class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pivot = INT_MAX;

        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == INT_MAX) {
            reverse(nums.begin(), nums.end());
        } else {            
            for(int j = n-1; j > pivot; j--) {
                if(nums[j] > nums[pivot]) {
                    swap(nums[j], nums[pivot]);
                    break;
                }
            }
            reverse(nums.begin()+pivot+1, nums.end());
        }
    }
};
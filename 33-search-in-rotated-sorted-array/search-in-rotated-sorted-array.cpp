class Solution {
public:

    int binarySearch(int si, int ei, vector<int>& nums, int target) {
        if(si > ei) {
            return -1;
        }

        int mid = si + (ei - si)/2;
        if(nums[mid] == target) {
            return mid;
        } else {
            if(nums[si] <= nums[mid]) {
                if(nums[si] <= target && target <= nums[mid]) {
                    return binarySearch(si, mid-1, nums, target);
                } else {
                    return binarySearch(mid+1, ei, nums, target);
                }
            } else {
                if(nums[mid] <= target && target <= nums[ei]) {
                    return binarySearch(mid+1, ei, nums, target);
                } else {
                    return binarySearch(si, mid-1, nums, target);
                }
            }
        }
    }

    int search(vector<int>& nums, int target) {
        int si = 0, ei = nums.size()-1;

        return binarySearch(si, ei, nums, target);
    }
};
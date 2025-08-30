class Solution {
public:
    int findSingle(int si, int ei, vector<int>& nums) {
        if(si == ei) {
            return nums[si];
        }

        int n = nums.size();
        int mid = si + (ei - si)/2;

        if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];
        if(mid == n-1 && nums[mid] != nums[mid-2]) return nums[mid];

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
            return nums[mid];
        }

        if(mid % 2 == 0) {
            if(nums[mid] == nums[mid - 1]) {
                return findSingle(si, mid-1, nums);
            } else {
                return findSingle(mid+1, ei, nums);
            }
        } else {
            if(nums[mid] == nums[mid - 1]) {
                return findSingle(mid+1, ei, nums);
            } else {
                return findSingle(si, mid-1, nums);
            }
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), si = 0, ei = n-1;
        if(n == 1) return nums[0];

        return findSingle(si, ei, nums);
    }
};
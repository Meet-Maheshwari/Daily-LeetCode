class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int si = 0, ei = n-1;
        int mini = INT_MAX;

        while(si <= ei) {
            int mid = si + (ei-si)/2;

            if(si == ei) return nums[si];
            
            if(nums[si] == nums[mid] && nums[mid] == nums[ei]) {
                si++;
                ei--;
            } else if(nums[si] <= nums[mid] && nums[mid] <= nums[ei]) {
                ei = mid;
            } else if(nums[si] <= nums[mid]) {
                si = mid+1;
            } else {
                ei = mid;
            }
        }

        return nums[si];
    }
};
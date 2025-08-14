class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right = m-1;
        int left = 0;

        while(right >= 0 && left < n) {
            if(nums1[right] >= nums2[left]) {
                swap(nums1[right], nums2[left]);
                right--; 
                left++;
            } else {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());

        for(int i = m, x = 0; i < m+n; i++) {
            nums1[i] = nums2[x++];
        }
    }
};
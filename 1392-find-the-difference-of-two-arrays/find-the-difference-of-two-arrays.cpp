class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> ans1, ans2;

        for(auto& num : s1) {
            if(!s2.count(num)) {
                ans1.push_back(num);
            }
        }
        for(auto& num : s2) {
            if(!s1.count(num)) {
                ans2.push_back(num);                
            }
        }

        return {ans1, ans2};
    }
};
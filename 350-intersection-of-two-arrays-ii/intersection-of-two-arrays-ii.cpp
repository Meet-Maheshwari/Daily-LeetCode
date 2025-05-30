class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> hash;
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            hash[num]++;
        }   

        for(int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];
            if(hash.count(num)) {
                ans.push_back(num);
                hash[num]--;
                if(hash[num] == 0) hash.erase(num);
            }
        }
        return ans;
    }
};
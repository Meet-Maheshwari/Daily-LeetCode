class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), maj = n/2;
        unordered_map<int, int>freq;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > maj) {
                ans = nums[i];
                break;
            };
        }

        return ans;
    }
};
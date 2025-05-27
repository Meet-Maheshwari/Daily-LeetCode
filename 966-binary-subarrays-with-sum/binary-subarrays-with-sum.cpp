class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> hash; //sum, count

        hash[0] = 1;
        int sum = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(hash.find(sum - goal) != hash.end()) {
                ans += hash[sum-goal];
            }

            if(hash.find(sum) != hash.end()) {
                hash[sum]++;
            } else {
                hash[sum] = 1;
            }
        }

        return ans;
    }
};
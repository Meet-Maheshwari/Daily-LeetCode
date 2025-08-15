class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        map<int, int> colors;

        for(int i = 0; i < n; i++) {
            colors[nums[i]]++;
        }

        for(int i = 0; i < n; i++) {
            if(colors[0] > 0) {
                nums[i] = 0;
                colors[0]--;
                continue;
            }
            if(colors[1] > 0) {
                nums[i] = 1;
                colors[1]--;
                continue;
            }
            if(colors[2] > 0) {
                nums[i] = 2;
                colors[2]--;
                continue;
            }
        }
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax (n, INT_MIN);
        vector<int> rightMax(n, INT_MIN);

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
            rightMax[n-i-1] = max(rightMax[n-i], height[n-i]); 
        }

        int water = 0;
        for(int i = 1; i < n-1; i++) {
            int maxH = min(leftMax[i], rightMax[i]);
            if(maxH - height[i] > 0) {
                water += maxH - height[i];
            } 
        }

        return water;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), p = 0, q = n-1;
        int maxWater = 0;
        
        while(p < q) {
            int H = min(height[p], height[q]);
            int W = q - p;
            int water = H * W;

            maxWater = max(water, maxWater);

            if(height[p] <= height[q]) {
                p++;
            } else {
                q--;
            }
        }
        return maxWater;
    }
};
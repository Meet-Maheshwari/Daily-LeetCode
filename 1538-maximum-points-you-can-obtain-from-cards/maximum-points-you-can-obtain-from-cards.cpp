class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, n = cardPoints.size();

        int leftSum = 0, rightSum = 0, maxSum = 0;

        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        ans = max(ans, leftSum + rightSum);
        
        int l = k-1, r = n-1;

        while(l >= 0) {
            leftSum -= cardPoints[l];
            rightSum += cardPoints[r];
            l--;
            r--;
            ans = max(ans, leftSum + rightSum);
        }

        return ans;
    }
};
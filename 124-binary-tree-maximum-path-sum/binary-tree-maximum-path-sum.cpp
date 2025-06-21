/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;

    int maxPathSumHelper(TreeNode* root, int& sum) {
        if(root == NULL) {
            return 0;
        }

        int leftSum = max(0, maxPathSumHelper(root->left, sum));
        int rightSum = max(0, maxPathSumHelper(root->right, sum));
        int currSum = root->val + leftSum + rightSum;

        maxSum = max(currSum, maxSum);

        return root-> val + max(leftSum, rightSum);
    }


    int maxPathSum(TreeNode* root) {
        int sum = 0;
        maxPathSumHelper(root, sum);
        return maxSum;
    }
};
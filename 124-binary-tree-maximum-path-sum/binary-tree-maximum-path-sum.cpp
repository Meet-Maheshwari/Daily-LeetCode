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

    int maxPathSumHelper(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftSum = maxPathSumHelper(root->left);
        int rightSum = maxPathSumHelper(root->right);

        int currSum1 = root -> val;
        int currSum2 = root -> val + max(leftSum, rightSum);
        int currSum3 = root -> val + leftSum + rightSum;

        maxSum = max(maxSum, max(currSum1, max(currSum2, currSum3)));

        return root -> val + max(0, max(leftSum, rightSum));
    }


    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return maxSum;
    }
};
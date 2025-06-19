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
    int maxLen = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {-1, -1};  // base: -1 so when +1 becomes 0

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftZigZag = 1 + left.second;   // left move => then right
        int rightZigZag = 1 + right.first;  // right move => then left

        maxLen = max({maxLen, leftZigZag, rightZigZag});

        return {leftZigZag, rightZigZag};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
};





















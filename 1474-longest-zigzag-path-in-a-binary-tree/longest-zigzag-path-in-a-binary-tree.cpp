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
    void findTotal(TreeNode* root, int dir, int currLen) {
        if(root == NULL) return;

        maxLen = max(maxLen, currLen);
        findTotal(root -> left, 0, dir?currLen+1:1 );
        findTotal(root -> right, 1, dir?1:currLen+1 );
    }

    int longestZigZag(TreeNode* root) {
        findTotal(root, 0, 0);
        findTotal(root, 1, 0);
        return maxLen;
    }
};




















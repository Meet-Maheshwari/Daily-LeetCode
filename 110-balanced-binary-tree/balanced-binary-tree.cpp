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
    int checkBalanced(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftDepth = checkBalanced(root -> left);
        int rightDepth = checkBalanced(root -> right);

        if(leftDepth == -1 || rightDepth == -1) {
            return -1;
        }

        if(abs(leftDepth - rightDepth) > 1) {
            return -1;
        }

        int currDepth = 1 + max(leftDepth, rightDepth);
        return currDepth;
    }
        

    bool isBalanced(TreeNode* root) {
        int ans = checkBalanced(root);
        return ans != -1;        
    }
};

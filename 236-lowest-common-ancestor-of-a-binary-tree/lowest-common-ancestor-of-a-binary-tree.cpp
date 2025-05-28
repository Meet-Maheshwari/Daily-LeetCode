/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        if(root == p || root == q) {
            return root;
        }

        TreeNode* leftHalf = lca(root->left, p, q);
        TreeNode* rightHalf = lca(root->right, p, q);

        if(leftHalf != NULL && rightHalf != NULL) {
            return root;
        }

        if(leftHalf != NULL) return leftHalf;
        return rightHalf;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = lca(root, p, q);

        return ans;
    }
};
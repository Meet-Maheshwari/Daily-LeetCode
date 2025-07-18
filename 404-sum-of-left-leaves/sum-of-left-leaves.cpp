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
    int sumOfLeft(TreeNode* root, int par) {
        if(root == NULL) {
            return 0;
        }

        if(root -> left == NULL && root ->right == NULL) {
            if(par) {
                return root -> val;
            } else {
                return 0;
            }
        }

        int leftLeaf = sumOfLeft(root->left, 1);
        int rightLeaf = sumOfLeft(root->right, 0);

        return leftLeaf+rightLeaf;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeft(root, 0);
    }
};
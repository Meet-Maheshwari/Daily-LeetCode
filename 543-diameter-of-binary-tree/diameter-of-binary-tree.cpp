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
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftH = height(root-> left);
        int rightH = height(root-> right);

        int curr = 1 + max(leftH, rightH);
        return curr;
    }

    void maxDiam(int& m, TreeNode* root) {
        if(root == NULL) {
            return;
        }

        int leftHeight = 0, rightHeight = 0;
        if(root -> left) {
            leftHeight = height(root -> left);
        }
        if(root -> right) {
            rightHeight = height(root -> right);
        }

        int currDiam = leftHeight + rightHeight;
        m = max(m, currDiam);

        maxDiam(m, root->left);
        maxDiam(m, root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int m = 0;
        maxDiam(m, root);
        return m;
    }
};
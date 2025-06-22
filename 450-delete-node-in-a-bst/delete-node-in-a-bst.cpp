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

    TreeNode* inorderSuccessor(TreeNode* root) {
        while(root->left!=NULL) {
            root=root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(key < root -> val) {
            root -> left = deleteNode(root->left, key);
        }

        if(key > root -> val) {
            root -> right = deleteNode(root->right, key);
        }

        if(key == root ->val) {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            if (root->left == NULL) {
                TreeNode* node = root->right;
                delete root;
                return node;
            } else if (root->right == NULL) {
                TreeNode* node = root->left;
                delete root;
                return node;
            }

            TreeNode* IS = inorderSuccessor(root->right);
            root -> val = IS -> val;
            root -> right = deleteNode(root->right, IS->val);
            return root;
        }
        return root;
    }
};
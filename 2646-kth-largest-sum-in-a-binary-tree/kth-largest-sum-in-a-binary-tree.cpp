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

        int leftH = height(root -> left);
        int rightH = height(root -> right);

        return 1 + max(leftH, rightH);
    }

    void countLevelSum(TreeNode* root, int level, vector<long long>& levelSum) {
        if(root == NULL) {
            return;
        }

        levelSum[level] += root -> val;
        countLevelSum(root->left, level+1, levelSum);
        countLevelSum(root->right, level+1, levelSum);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        int treeHeight = height(root);
        if(k > treeHeight) return -1;
        vector<long long> levelSum(treeHeight, 0);

        countLevelSum(root, 0, levelSum);
        sort(levelSum.begin(), levelSum.end());

        return levelSum[levelSum.size() - k];
    }
};
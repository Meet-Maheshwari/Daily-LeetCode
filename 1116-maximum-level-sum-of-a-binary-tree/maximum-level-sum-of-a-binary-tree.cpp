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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int maxSum = root->val;
        int maxLevel = 1;
        int currLevel = 1;

        while (!Q.empty()) {
            int size = Q.size();
            int levelSum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                levelSum += node->val;

                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currLevel;
            }

            currLevel++;
        }

        return maxLevel;    }
};
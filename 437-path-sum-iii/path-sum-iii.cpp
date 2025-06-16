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
    int findSum(TreeNode* root, long long currSum, int tar, unordered_map<long long, int>& prefixSum) {
        if(root == NULL) return 0;

        currSum += root -> val;

        int numPathsToCurr = prefixSum[currSum - tar];

        prefixSum[currSum]++; 

        int leftPath = findSum(root->left, currSum, tar, prefixSum);
        int rightPath = findSum(root->right, currSum, tar, prefixSum);

        prefixSum[currSum]--;

        return numPathsToCurr+ leftPath + rightPath;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return findSum(root, 0, targetSum, prefixSum);        
    }
};






























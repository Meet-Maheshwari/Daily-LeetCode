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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
        if(root == NULL) return {};      
        vector<vector<int>> result;
        vector<int> ans;

        stack<TreeNode*> s1, s2;

        s1.push(root);
        bool rev = true;

        while(!s1.empty() || !s2.empty()) {
            if(rev) {
                while(!s1.empty()) {
                    TreeNode* curr = s1.top();
                    s1.pop();
                    ans.push_back(curr->val);

                    if(curr->left) {
                        s2.push(curr->left);
                    }
                    if(curr->right) {
                        s2.push(curr->right);
                    }
                }
            } else {
                while(!s2.empty()) {
                    TreeNode* curr = s2.top();
                    s2.pop();
                    ans.push_back(curr->val);

                    if(curr->right) {
                        s1.push(curr->right);
                    }
                    if(curr->left) {
                        s1.push(curr->left);
                    }
                }
            }
            result.push_back(ans);
            ans = {};
            rev = ! rev;
        }

        return result;
    }
};
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};

        map<int, int> mp;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 0));

        while(!Q.empty()) {
            pair<TreeNode*, int> curr = Q.front();
            Q.pop();

            if(mp.count(curr.second) == 0) {
                mp[curr.second] = curr.first->val;
            }
            if(curr.first->right != NULL) {
                Q.push(make_pair(curr.first->right, curr.second+1));
            }

            if(curr.first->left != NULL) {
                Q.push(make_pair(curr.first->left, curr.second+1));
            }
        }
        vector<int> ans;
        for(auto el : mp){
            ans.push_back(el.second);
        }

        return ans;
    }
};
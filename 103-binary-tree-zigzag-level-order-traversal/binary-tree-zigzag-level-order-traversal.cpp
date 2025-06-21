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

        deque<TreeNode*> deq;
        bool rev = false;
        deq.push_back(root);

        while(!deq.empty()) {
            int size = deq.size();

            for(int i = 0; i < size; i++) {                
                if (rev) {
                    TreeNode* curr = deq.back();
                    deq.pop_back();
                    ans.push_back(curr->val);

                    if (curr->right) deq.push_front(curr->right);
                    if (curr->left)  deq.push_front(curr->left);
                }
                
                // Else push left first
                else {
                    TreeNode* curr = deq.front();
                    deq.pop_front();
                    ans.push_back(curr->val);

                    if (curr->left)  deq.push_back(curr->left);
                    if (curr->right) deq.push_back(curr->right);
                }
            }
            
            rev = !rev;
            result.push_back(ans);
            ans = {};
        }
        return result;
    }
};
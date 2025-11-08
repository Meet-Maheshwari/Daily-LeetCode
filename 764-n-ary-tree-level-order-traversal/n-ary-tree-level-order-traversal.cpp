/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<Node*> Q;
        Q.push(root);
        Q.push(NULL);

        vector<int> nodes;
        while(!Q.empty()) {
            Node* curr = Q.front();
            Q.pop();

            if(curr == NULL) {
                ans.push_back(nodes);
                nodes.clear();
                if(!Q.empty()){

                    Q.push(NULL);
                } else {
                    break;
                }
            } else {
                nodes.push_back(curr->val);
                for(Node* child : curr->children) {
                    Q.push(child);
                }
            }
        }

        return ans;       
    }
};
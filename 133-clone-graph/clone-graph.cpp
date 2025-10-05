/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        vector<Node*> clone(101, NULL);
        vector<bool> vis(101, false);
        clone[node->val] = new Node(node->val);

        vis[node->val] = true;
        queue<Node*> Q;
        Q.push(node);

        while(!Q.empty()) {
            Node* curr = Q.front();
            Q.pop();

            for(Node* v : curr->neighbors) {
                if(!vis[v->val]) {
                    vis[v->val] = true;
                    clone[v->val] = new Node(v->val);
                    Q.push(v);
                }
                clone[curr -> val]->neighbors.push_back(clone[v->val]);
            }
        }

        return clone[node->val];
    }
};
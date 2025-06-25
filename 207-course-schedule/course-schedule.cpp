class Solution {
public:
    bool findCycle(list<int>* l, int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if(!vis[v]) {
                if(findCycle(l, v, vis, recPath)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<bool> vis (V, false);
        vector<bool> recPath(V, false);

        list<int>*l = new list<int>[V];

        for(int i = 0; i < graph.size(); i++) {
            l[graph[i][1]].push_back(graph[i][0]);
        }

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(findCycle(l, i, vis, recPath)) {
                    return false;
                }
            }
        }
        return true;
    }
};
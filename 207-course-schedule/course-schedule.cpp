class Solution {
public:
    bool findCycle(int src, vector<bool>& recPath, vector<bool>& vis, vector<vector<int>>& graph) {
        vis[src] = true;
        recPath[src] = true;
        int V = graph.size();
        
        for(int i = 0; i < V; i++) {
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src) {
                if(!vis[v]) {
                    if(findCycle(v, recPath, vis, graph)) {
                        return true;
                    }
                } else{
                    if(recPath[v]) {
                        return true;
                    }
                }
            }
        }

        recPath[src] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<bool> vis (V, false);
        vector<bool> recPath (V, false);
        for(int i = 0; i < V; i++) {
            if(findCycle(i, recPath, vis, graph)) {
                return false;
            }
        }
        return true;
    }
};
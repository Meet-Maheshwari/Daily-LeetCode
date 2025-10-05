class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        
        vector<int> color(V, -1);
        queue<int> Q;

        for(int u = 0; u < V; u++) {            
            if(color[u] == -1) {
                Q.push(u);
                color[u] = 0;

                while(!Q.empty()) {
                    int curr = Q.front();
                    Q.pop();

                    for(int v : graph[curr]) {
                        if(color[v] == -1) {
                            color[v] = !color[curr];
                            Q.push(v);
                        } else {
                            if(color[curr] == color[v])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
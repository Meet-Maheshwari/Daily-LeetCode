class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        int src = 0, dst = n-1;
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < roads.size(); i++) {
           int u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[src] = 0;
        ways[src] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, src});

        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();

            int u = curr.second; long long wt = curr.first;
            vector<pair<int, int>> neighbors = graph[u];

            for(auto edge : neighbors) {
                int v = edge.first; long long vwt = edge.second;

                if(dist[v] > vwt + wt) {
                    dist[v] = vwt + wt;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                } else if(dist[v] == vwt + wt) {
                    ways[v] = (ways[u] + ways[v]) % MOD ;
                }
            }
        }

        return ways[dst] % MOD;
    }
};
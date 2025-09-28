class Solution {
public:
    class Edges{
    public:
        int v;
        int t;

        Edges(int v, int t) {
            this -> v = v;
            this -> t = t;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edges>> graph(n+1);

        for(int i = 0; i < times.size(); i++) {
            graph[times[i][0]].push_back(Edges(times[i][1], times[i][2]));
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // time, src

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();

            int u = curr.second, t = curr.first;

            vector<Edges> neighbors = graph[u];
            for(Edges edge : neighbors) {
                if(dist[edge.v] > t + edge.t) {
                    dist[edge.v] = t + edge.t;
                    pq.push({dist[edge.v], edge.v});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i = 1; i < dist.size(); i++) {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};
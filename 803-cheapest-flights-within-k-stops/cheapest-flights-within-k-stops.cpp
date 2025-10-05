class Solution {
public:

class Info{
public:
    int u, stops;
    long long cost;

    Info(int u, long long cost, int stops) {
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }

    bool operator <(const Info& other) const {
        return this->cost > other.cost; 
    }
};
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        } 

        vector<int> dist(n, INT_MAX);
        queue<Info> Q;
        dist[src] = 0;
        Q.push(Info(src, 0, -1));

        while(!Q.empty()) {
            Info curr = Q.front();
            Q.pop();

            int u = curr.u;
            int cost = curr.cost;
            int stops = curr.stops;

            for(pair<int, int> edge : graph[u]) {
                int v = edge.first;
                int wt = edge.second;

                if(dist[v] > cost + wt && stops + 1 <= k) {
                    dist[v] = cost + wt;
                    Q.push(Info(v, dist[v], stops+1));
                }
            }
        } 

        if(dist[dst] == INT_MAX) {
            return -1;
        }

        return dist[dst];
    }
};













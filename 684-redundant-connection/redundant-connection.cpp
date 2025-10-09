class DisjointSet {
public:
    int x;
    vector<int> par, rank;

    DisjointSet(int x) {
        this -> x = x;
        par.resize(x, 0);
        rank.resize(x, 0);
        for(int i = 0; i < x; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v) {
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]) {
            par[parV] = parU;
            rank[parU]++;
        } else if(rank[parU] > rank[parV]) {
            par[parV] = parU;
        } else {
            par[parU] = parV;
        }
    }

    vector<pair<int, int>> krushkalsAlgorithm(vector<vector<int>>& edges) {
        vector<pair<int, int>> ans;

        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            int parU = find(u), parV = find(v);

            if(parU == parV) {
                ans.push_back({u, v});
            } else {
                unionByRank(u, v);
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);
        vector<pair<int, int>> ans = ds.krushkalsAlgorithm(edges);
        int m = ans.size();
        vector<int>  res= {ans[0].first, ans[0].second};
        return res;
    }
};
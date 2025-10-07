class DisjointSet {
public:
    int x;
    vector<int> par;
    vector<int> rank;

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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), rowMax = 0, colMax = 0;

        for(vector<int> it : stones) {
            rowMax = max(rowMax, it[0]);
            colMax = max(colMax, it[1]);
        }

        DisjointSet ds(rowMax+colMax+2);

        unordered_map<int, int> map;
        for(vector<int> it : stones) {
            ds.unionByRank(it[0], it[1] + rowMax + 1);
            map[it[0]] = 1;
            map[it[1] + rowMax + 1] = 1;
        }

        int count = 0;
        for(auto it : map) {
            if(ds.find(it.first) == it.first) {
                count++;
            }
        }

        return n - count;
    }
};



















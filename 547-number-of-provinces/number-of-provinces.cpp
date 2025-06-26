class Solution {
public:
    void dfs(int src, list<int>*l, vector<bool>& vis) {
        vis[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if(!vis[v]) {
                dfs(v, l, vis);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        list<int> * l = new list<int>[n+1];
        vector<bool> vis(n+1, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    l[i+1].push_back(j+1);
                    l[j+1].push_back(i+1);
                }
            }
        }  

        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                dfs(i, l, vis);
                count++;
            }
        }

        return count;
    }
};
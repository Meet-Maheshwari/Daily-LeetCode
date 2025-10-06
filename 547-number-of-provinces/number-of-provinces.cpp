class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> grid(n+1);
        vector<bool> vis(n+1, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    grid[i+1].push_back(j+1);
                    grid[j+1].push_back(i+1);
                }
            }
        }

        queue<int> Q;
        int count = 0;

        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                count++;
                Q.push(i);

                while(!Q.empty()) {
                    int curr = Q.front();
                    Q.pop();

                    for(int v : grid[curr]) {
                        if(!vis[v]) {
                            vis[v] = true;
                            Q.push(v);
                        }
                    }
                }
            }
        }

        return count;
    }
};
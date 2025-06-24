class Solution {
public:
    // int minSteps = INT_MAX;

    // void findExit(vector<vector<char>>& maze, int i, int j, int n, int m, int count) {
    //     if(i >= n || i < 0 || j >= m || j < 0 || maze[i][j] == '+') {
    //         return;
    //     }
        
    //     if((i == 0 || i == n-1 || j == 0 || j == m-1) && count != 0) {
    //         minSteps = min(minSteps, count);
    //         return;
    //     }

    //     maze[i][j] = '+';

    //     findExit(maze, i-1, j, n, m, count+1);
    //     findExit(maze, i, j+1, n, m, count+1);
    //     findExit(maze, i+1, j, n, m, count+1);
    //     findExit(maze, i, j-1, n, m, count+1);

    //     maze[i][j] = '.';
    // }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [pos, steps] = q.front(); q.pop();
            int i = pos.first, j = pos.second;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && maze[ni][nj] == '.') {
                    if (ni == 0 || ni == n-1 || nj == 0 || nj == m-1)
                        return steps + 1;

                    maze[ni][nj] = '+';
                    q.push({{ni, nj}, steps + 1});
                }
            }
        }

        return -1;
    }
};
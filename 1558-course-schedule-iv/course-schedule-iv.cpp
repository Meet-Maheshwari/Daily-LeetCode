class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));

        for(int i = 0; i < prerequisites.size(); i++) {
            grid[prerequisites[i][0]][prerequisites[i][1]] = true;
        }

        for(int k = 0; k < numCourses; k++) {
            for(int i = 0; i < numCourses; i++) {
                for(int j = 0; j < numCourses; j++) {
                    if(i==k || j==k || i==j) continue;
                    if(grid[i][k] && grid[k][j]) grid[i][j] = true;
                }
            }
        }

        vector<bool> ans;
        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(grid[queries[i][0]][queries[i][1]]);
        }

        return ans;
    }
};
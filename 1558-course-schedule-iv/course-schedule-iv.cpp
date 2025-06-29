class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> floydMatrix(numCourses, vector<int>(numCourses, 0));

        for(int i = 0; i < prerequisites.size(); i++) {
            floydMatrix[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }

        for(int k = 0; k < numCourses; k++) {
            for(int i = 0; i < numCourses; i++) {
                for(int j = 0; j < numCourses; j++) {
                    if(floydMatrix[i][k] && floydMatrix[k][j]) {
                        if(!floydMatrix[i][j]) {
                            floydMatrix[i][j] = 1;
                        }
                    }
                }
            }
        }

        vector<bool> ans(queries.size(), false);
        
        for(int i = 0; i < queries.size(); i++) {
            if(floydMatrix[queries[i][0]][queries[i][1]]) {
                ans[i] = true;
            }
        }

        return ans;
    }
};
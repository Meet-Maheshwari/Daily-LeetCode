class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> occurance;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                occurance.push_back(i);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int minDist = INT_MAX;
            for(int j = 0; j < occurance.size(); j++) {
                int dist = abs(occurance[j] - i);
                minDist = min(minDist, dist);
            }
            ans.push_back(minDist);
        }

        return ans;
    }
};
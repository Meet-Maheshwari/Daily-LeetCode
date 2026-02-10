class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            vec.push_back({intervals[i][0], i});
        }

        sort(vec.begin(), vec.end(), compare);

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int key = intervals[i][1];
            int si = 0, ei = n-1;
            int right = -1;

            while(si <= ei) {
                int mid = si + (ei-si)/2;

                if(vec[mid].first >= key) {
                    right = vec[mid].second;
                    ei = mid-1;
                } else {
                    si = mid+1;
                }
            } 
            ans.push_back(right);
        }

        return ans;
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        int lastEnd = intervals[0][1], ans = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(lastEnd > intervals[i][0]) {
                ans++;
            } else {
                lastEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
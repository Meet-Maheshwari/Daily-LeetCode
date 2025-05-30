class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;

        for(int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }
        unordered_set<int> s;

        for(pair<int, int> el : map) {
            if(s.count(el.second)) return false;
            s.insert(el.second);
        }

        return true;
    }
};
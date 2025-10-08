class Solution {
public:
    long long countSubstrings(string s, char c) {
        unordered_set<int> set;
        long long count = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                count += set.size() + 1;
                set.insert(i);
            }
        }

        return count;
    }
};
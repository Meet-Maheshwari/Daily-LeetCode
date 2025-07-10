class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n != m) return false;

        unordered_set<int> s1(word1.begin(), word1.end());
       for(int i = 0; i < word2.size(); i++) {
            if(s1.find(word2[i]) == s1.end()) {
                return false;
            }
       }

        vector<int> freq1(26, 0), freq2(26, 0);

        for(int i = 0; i < n; i++) {
            freq1[word1[i] - 'a']++;
        }

        for(int j = 0; j < m; j++) {
            freq2[word2[j] - 'a']++;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) return false;
        }

        return true;
    }
};
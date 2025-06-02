class Solution {
public:
    bool closeStrings(string word1, string word2) {
       if(word1.length() != word2.length()) {
            return false;
       }    

        unordered_set<int> s1(word1.begin(), word1.end());
       for(int i = 0; i < word2.size(); i++) {
            if(s1.find(word2[i]) == s1.end()) {
                return false;
            }
       }

       vector<int>ans1(26, 0), ans2(26, 0);
        for(int i = 0; i < word1.size(); i++) {
            ans1[word1[i] - 'a']++;
            ans2[word2[i] - 'a']++;
        }

        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());

        for(int i = 0; i < 26; i++) {
            if(ans1[i] != ans2[i]) return false;
        }
        return true;
    }
};
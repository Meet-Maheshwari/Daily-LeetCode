class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>present(26);

        for(int i = 0; i < 26; i++) {
            present[order[i]-'a'] = i;
        }

        int n = words.size();
        for(int i = 0; i < n-1; i++) {
            string str1 = words[i], str2 = words[i+1];

            int len = min(str1.size(), str2.size());
            int j = 0;
            for(; j < len; j++) {
                if(str1[j] != str2[j]) {
                    if(present[str1[j] - 'a'] > present[str2[j] - 'a']) {
                        return false;
                    } 
                    break;
                }
            }

            if(j == len && str1.size() > str2.size()) {
                return false;
            }
        }

        return true;
    }
};
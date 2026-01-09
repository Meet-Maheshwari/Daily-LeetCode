class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        return rev == s;
    }

    void findAllPalindromes(string s, int end, vector<string>& store) {
        int n = s.size();
        if(end == n) {
            ans.push_back(store);
        }

        for(int idx = end; idx < n; idx++) {
            string str = s.substr(end, idx-end+1);

            if(isPalindrome(str)) {
                store.push_back(str);
                findAllPalindromes(s, idx+1, store);
                store.pop_back();
            } 
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> palindromes;
        findAllPalindromes(s, 0, palindromes);

        return ans;
    }
};
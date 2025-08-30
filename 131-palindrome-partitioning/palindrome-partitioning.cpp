class Solution {
public:
    bool isPalindrome(string str) {
        string temp = str;
        reverse(temp.begin(), temp.end());

        return temp == str;
    }

    void findAllPalindromes(string s, vector<string>& palindromes, vector<vector<string>>& ans) {
        if(s.size() == 0) {
            ans.push_back(palindromes);
        }

        int n = s.size();

        for(int i = 0; i < n; i++) {
            string leftStr = s.substr(0, i+1);
            if(isPalindrome(leftStr)) {
                palindromes.push_back(leftStr);
                findAllPalindromes(s.substr(i+1), palindromes, ans);
                palindromes.pop_back();
            }
        }  
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palindromes;
        
        findAllPalindromes(s, palindromes, ans);

        return ans;
    }
};
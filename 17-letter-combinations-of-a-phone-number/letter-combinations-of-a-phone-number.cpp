class Solution {
public:
    void combination(vector<string>& matrix, vector<string>& ans, string& str, int idx, int n) {
        if(idx == n) {
            ans.push_back(str);
            return;
        }

        for(int i = 0; i < matrix[idx].size(); i++) {
            str += matrix[idx][i];
            combination(matrix, ans, str, idx+1, n);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        map<char, string> hash;
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";

        vector<string> matrix;
        for(int i = 0; i < digits.size(); i++) {
            matrix.push_back(hash[digits[i]]);
        }

        vector<string> ans;
        string str;
        combination(matrix, ans, str, 0, matrix.size());

        return ans;
    }
};
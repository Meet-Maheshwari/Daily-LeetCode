class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char> rev(n);

        for(int i = n-1; i >= 0; i--) {
            rev[i] = s[n-i-1];
        }

        s = rev;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, ei = s.size()-1;

        while(st <= ei) {
            if(!isalnum(s[st])) {
                st++;
            } else if(!isalnum(s[ei])) {
                ei--;
            } else if(tolower(s[st]) != tolower(s[ei])) {
                return false;
            } else {
                st++;
                ei--;
            }
        }

        return true;
    }
};

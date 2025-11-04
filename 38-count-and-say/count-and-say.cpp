class Solution {
public:
    string recursiveLogic(int idx, string str, int n) {
        if(idx > n) return str;
        
        int count = 0;
        char ch = str[str.size()-1];
        string newStr = "";

        for(int i = str.size()-1; i >= 0; i--) {
            char num = str[i];
            if(num == ch) count++;

            if(num != ch) {
                newStr = to_string(count) + ch + newStr;
                count = 1;
                ch = num;
            }
        }
        newStr = to_string(count) + ch + newStr;
        return recursiveLogic(idx+1, newStr, n);
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        return recursiveLogic(2, "1", n);
    }
};
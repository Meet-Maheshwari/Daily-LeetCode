class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        int n = str.size(), count = 0, maxCount = 0;
        vector<bool> validArr(n, false);

        for(int i = 0; i < n; i++) {
            if(str[i] == '(') {
                s.push(i);
            } else {
                if(!s.empty()) {
                    validArr[i] = true;
                    validArr[s.top()] = true;
                    s.pop();
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(validArr[i]) {
                count += 1;
                maxCount = max(count, maxCount);
            } else {
                count = 0;
            }
        }

        return maxCount;
    }
};
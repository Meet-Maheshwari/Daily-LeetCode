class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != ']') {
                st.push(c);
            } else {
                string decodedStr = "";
                while (!st.empty() && st.top() != '[') {
                    decodedStr = st.top() + decodedStr;
                    st.pop();
                }
                st.pop();

                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int count = stoi(numStr);

                string repeated = "";
                for (int i = 0; i < count; ++i) {
                    repeated += decodedStr;
                }

                for (char ch : repeated) {
                    st.push(ch);
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

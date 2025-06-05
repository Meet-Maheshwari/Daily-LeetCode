class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != ']') {
                st.push(c);
            } else {
                // Step 1: Get the string inside the brackets
                string decodedStr = "";
                while (!st.empty() && st.top() != '[') {
                    decodedStr = st.top() + decodedStr;
                    st.pop();
                }

                // Remove the '['
                st.pop();

                // Step 2: Get the number (could be more than 1 digit)
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int count = stoi(numStr);

                // Step 3: Repeat the decodedStr 'count' times
                string repeated = "";
                for (int i = 0; i < count; ++i) {
                    repeated += decodedStr;
                }

                // Step 4: Push repeated characters back to the stack
                for (char ch : repeated) {
                    st.push(ch);
                }
            }
        }

        // Final step: Build the result from stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

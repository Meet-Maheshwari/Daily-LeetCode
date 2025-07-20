class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        int n = tokens.size();

        for(int i = 0; i < n; i++) {
            string ch = tokens[i];

            if(ch != "+" && ch != "-" && ch != "*" && ch != "/") {
                st.push(ch);              
            } else {
                int op1 = stoi(st.top());
                st.pop();
                int op2 = stoi(st.top());
                st.pop();
                if(ch == "+") st.push(to_string(op2 + op1));
                if(ch == "-") st.push(to_string(op2 - op1));
                if(ch == "*") st.push(to_string(op2 * op1));
                if(ch == "/") st.push(to_string(op2 / op1));
            }
        }

        return stoi(st.top());
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop();  // top asteroid is destroyed
                } else if (abs(a) == st.top()) {
                    st.pop();  // both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // incoming asteroid is destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
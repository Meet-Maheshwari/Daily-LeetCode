class MinStack {
public:
    vector<int> st;
    vector<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(minSt.empty() || val < minSt.back()) {
            minSt.push_back(val);
        } else {
            minSt.push_back(minSt.back());
        }
    }
    
    void pop() {
        st.pop_back();
        minSt.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    };
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
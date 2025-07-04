class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!s.empty() && price >= s.top().first) {
            span += s.top().second;
            s.pop();
        }

        s.push(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
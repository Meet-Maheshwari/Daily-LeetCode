class RecentCounter {
public:
    vector<int> calls;
    RecentCounter() {
    }
    
    int ping(int t) {
        calls.push_back(t);
        int count = 0;
        for(int i = 0; i < calls.size(); i++) {
            if(calls[i] >= (t-3000) && calls[i] <= t) count++;
        }
        return count;
    } 
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
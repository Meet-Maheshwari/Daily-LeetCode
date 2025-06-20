class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> s;

    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            pq.push(i);
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = pq.top();
        s.erase(smallest);
        pq.pop();
        return smallest;
    }
    
    void addBack(int num) {
        if(!s.count(num)) {
            s.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
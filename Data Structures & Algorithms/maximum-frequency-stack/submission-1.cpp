class FreqStack {
    priority_queue<vector<int>> pq;
    unordered_map<int,int> count;
    int idx;
public:
    FreqStack() {
        idx = 0;
    }
    
    void push(int val) {
        count[val]++;
        pq.push({count[val], idx++, val});
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        count[val[2]]--;
        return val[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
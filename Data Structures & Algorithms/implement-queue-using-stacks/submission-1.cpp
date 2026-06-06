class MyQueue {
    stack<int> s, t;
    void help() {
        if (t.size() == 0) {
            int sz = s.size();
            while (sz-- > 0) {
                t.push(s.top());
                s.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        help();
        int val = t.top();
        t.pop();
        return val;
    }
    
    int peek() {
        help();
        int val = t.top();
        return val;
    }
    
    bool empty() {
        return t.empty() && s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
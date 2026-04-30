class MinStack {
    stack<int> vals, mi;
    int current_min;
public:
    MinStack() {
       current_min = INT_MAX; 
    }
    
    void push(int val) {
        vals.push(val);
        if (val <= current_min) {
            mi.push(current_min);
            current_min = val;
        }
    }
    
    void pop() {
        if (vals.top() == current_min) {
            current_min = mi.top();
            mi.pop();
        }
        vals.pop();
    }
    
    int top() {
       return vals.top(); 
    }
    
    int getMin() {
       return current_min; 
    }
};

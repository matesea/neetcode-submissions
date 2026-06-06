class StockSpanner {
    int idx;
    stack<pair<int,int>> s;
public:
    StockSpanner() {
       idx = 0; 
    }
    
    int next(int price) {
        while (!s.empty() && s.top().first <= price) {
            s.pop();
        }
        int res = idx - (!s.empty() ? s.top().second : -1);
        s.push({price, idx++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
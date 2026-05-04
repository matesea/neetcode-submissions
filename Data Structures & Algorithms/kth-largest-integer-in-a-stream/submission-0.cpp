class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for (auto& x: nums) {
            pq.push(x);
            if (pq.size() > n) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
       pq.push(val); 
       if (pq.size() > n)
        pq.pop();
        return pq.top();
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const vector<int>& v) -> unsigned long long {
            unsigned long long res = 0;
            for (auto& x: v) {
                res += x*x;
            }
            return res;
        };
        auto cmp = [&dist](const vector<int>& a, const vector<int>& b) -> bool {
            return dist(a) < dist(b);
        };
       priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp); 
       for (auto& p: points) {
        pq.push(p);
        if (pq.size() > k)
            pq.pop();
       }
       vector<vector<int>> res;
       while (pq.size() > 0) {
        res.push_back(pq.top());
        pq.pop();
       }
       return res;
    }
};

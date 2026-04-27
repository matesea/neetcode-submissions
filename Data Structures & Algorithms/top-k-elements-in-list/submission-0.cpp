class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> m; 
       for (auto& e: nums) {
        m[e]++;
       }
       vector<int> res;
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> p;
       for (auto& [key, val]: m) {
        p.push({val, key});
        if (p.size() > k)
            p.pop();
       }
       while (p.size() > 0) {
        vector<int> v = p.top();
        p.pop();
        res.push_back(v[1]);
       }
       return res;
    }
};

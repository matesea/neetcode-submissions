class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> res;

        auto cmp = [&arr, &x] (const int& i, const int& j) -> bool {
            int ai = abs(x - arr[i]);
            int aj = abs(x - arr[j]);
            return ai > aj || ai == aj && i > j;
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i)
            pq.push(i);
        while (res.size() < k) {
            int x = pq.top();
            pq.pop();
            res.push_back(arr[x]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
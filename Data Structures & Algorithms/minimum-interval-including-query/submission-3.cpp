class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        vector<int> res(queries.size(), -1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i = 0;
        vector<pair<int,int>> queries_with_index;
        for (int i = 0; i < queries.size(); ++i) {
            queries_with_index.push_back({queries[i], i});
        }
        sort(queries_with_index.begin(), queries_with_index.end());
        sort(intervals.begin(), intervals.end());
        
        for (auto& [q, idx]: queries_with_index) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            while (pq.size() > 0 && pq.top().second < q) {
                pq.pop();
            }
            res[idx] = pq.size() > 0 ? pq.top().first : -1;
        }
        return res;
    }
};

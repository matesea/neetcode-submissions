class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;
        int n = intervals.size();
        sort(sortedQueries.begin(), sortedQueries.end());
        unordered_map<int,int> result;
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int i = 0;
        for (auto& q: sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            while (pq.size() > 0 && pq.top().second < q) {
                pq.pop();
            }
            result[q] = pq.size() > 0 ? pq.top().first : -1;
        }
        vector<int> res;
        for (auto& q: queries) {
            res.push_back(result[q]);
        }
        return res;
    }
};

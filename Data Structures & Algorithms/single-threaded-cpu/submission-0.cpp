class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        int current = 0;
        int i = 0;
        vector<int> res;
        while (i < tasks.size() || pq.size() > 0) {
            if (i < tasks.size() && current < tasks[i][0])
                current = tasks[i][0];
            while (i < tasks.size() && tasks[i][0] <= current) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            if (pq.size() == 0)
                continue;
            auto v = pq.top();
            pq.pop();
            current += v[0];
            res.push_back(v[1]);
        }
        return res;
    }
};
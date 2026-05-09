class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> latency(n+1, INT_MAX);
        latency[k] = 0;
        queue<pair<int,int>> q;
        for (auto& t: times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        q.push({k, 0});
        int res = 0;
        while (q.size() > 0) {
            auto t = q.front();
            q.pop();
            int &cur = t.first, &lat = t.second;
            for (auto& p: adj[cur]) {
                int next = p.first;
                int new_lat = p.second + lat;
                if (latency[next] > new_lat) {
                    latency[next] = new_lat;
                    q.push({next, new_lat});
                }
            }
        }
        res = *max_element(latency.begin() + 1, latency.end());
        return (res == INT_MAX ? -1 : res);
    }
};

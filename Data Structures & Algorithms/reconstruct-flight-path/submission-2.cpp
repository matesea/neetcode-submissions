class Solution {
    void dfs(const string& current, unordered_map<string,vector<string>>& adj, vector<string>& path) {
        while (adj[current].size() > 0) {
            string next = adj[current].back();
            adj[current].pop_back();
            dfs(next, adj, path);
        }
        path.push_back(current);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       unordered_map<string,vector<string>> adj; 
       for (auto& t: tickets)
        adj[t[0]].push_back(t[1]);
       for (auto& [k, v]: adj)
        sort(v.rbegin(), v.rend());
        vector<string> path;
       dfs("JFK", adj, path);
       reverse(path.begin(), path.end());
       return path;
    }
};

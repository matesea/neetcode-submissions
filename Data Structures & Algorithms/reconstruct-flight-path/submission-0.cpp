class Solution {
    bool dfs(unordered_map<string,unordered_map<string,int>>& adj, vector<string>& f, int n) {
        if (f.size() == n+1) {
            return true;
        }
        string cur = f.back();
        vector<string> next_cities;
        for (auto& p: adj[cur]) {
            int count = p.second;
            string next = p.first;
            if (count > 0) {
                next_cities.push_back(next);
            }
        }
        sort(next_cities.begin(), next_cities.end());
        for (auto& next: next_cities) {
            f.push_back(next);
            adj[cur][next]--;
            if (dfs(adj, f, n))
                return true;
            adj[cur][next]++;
            f.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,unordered_map<string,int>> adj;
        int n = tickets.size();
        for (auto& t: tickets)
            adj[t[0]][t[1]]++;
        vector<string> flights = {"JFK"};
        dfs(adj, flights, n);
        return flights;
    }
};

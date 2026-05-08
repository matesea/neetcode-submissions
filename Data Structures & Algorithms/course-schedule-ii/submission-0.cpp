class Solution {
    bool dfs(vector<vector<int>>& adj, int i, vector<int>& s, vector<int>& visited) {
        visited[i] = 1;
        for (auto& next: adj[i]) {
            if (visited[next] == 1)
                return true;
            if (visited[next] == 0 && dfs(adj, next, s, visited))
                return true;
        }
        visited[i] = 2;
        s.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> s;
        vector<int> visited(n, 0);
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dfs(adj, i, s, visited))
                return {};
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

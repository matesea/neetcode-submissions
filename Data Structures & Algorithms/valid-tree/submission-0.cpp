class Solution {
    bool dfs(vector<vector<int>>& adj, int i, int prev, vector<int>& visited) {
        if (visited[i]) return visited[i] == 1;
        visited[i] = 1;
        for (auto& next: adj[i]) {
            if (next != prev && dfs(adj, next, i, visited))
                return true;
        }
        visited[i] = 2;
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() + 1 != n)
            return false;
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dfs(adj, i, -1, visited))
                return false;
        }
        return true;
    }
};

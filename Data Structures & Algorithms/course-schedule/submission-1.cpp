class Solution {
    bool dfs(vector<vector<int>>& adj, int i, vector<int>& visited) {
        visited[i] = 1;
        for (auto& next: adj[i]) {
            if (visited[next] == 1 || dfs(adj, next, visited))
                return true; // loop
        }
        visited[i] = 2;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for (auto& p: pre) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (dfs(adj, i, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};

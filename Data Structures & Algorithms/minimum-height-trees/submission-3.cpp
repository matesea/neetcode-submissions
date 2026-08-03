class Solution {
    pair<int,int> bfs(vector<vector<int>>& adj, int node) {
        queue<int> q;
        vector<bool> visited(adj.size(), false);
        int steps = 0, farthest = -1;

        q.push(node);
        visited[node] = true;
        while (q.size() > 0) {
            int sz = q.size();
            while (sz-- > 0) {
                int f = q.front();
                q.pop();
                farthest = f;
                // cout << "visit " << f << endl;
                for (auto& next: adj[f]) {
                    if (visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            ++steps;
        }
        return {farthest, steps - 1};
    }
    bool findCentroids(vector<vector<int>>& adj, vector<int>& path, int i, int parent, int target) {
        if (i == target) {
            path.push_back(i);
            return true;
        }
        for (auto& next: adj[i]) {
            if (parent == next) continue;
            if (findCentroids(adj, path, next, i, target)) {
                path.push_back(i);
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto p = bfs(adj, 0);
        auto q = bfs(adj, p.first);
        // cout << p.first << " " << q.first << endl;
        vector<int> path;
        
        findCentroids(adj, path, p.first, -1, q.first);

         if (path.size() % 2 == 1)
             return {path[path.size() / 2]};
         return {path[path.size()/2 - 1], path[path.size()/2]};
    }
};
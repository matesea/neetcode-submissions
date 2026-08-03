class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n); 
       vector<int> indegree(n, 0);
       if (n == 1) return {0};
       for (auto& e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        indegree[e[0]]++;
        indegree[e[1]]++;
       }
       queue<int> q;
       for (int i = 0; i < n; ++i) {
        if (indegree[i] == 1) {
            q.push(i);
        }
       }
       vector<int> res;
       while (q.size() > 0) {
        int sz = q.size();
        res.clear();
        while (sz-- > 0) {
            int f = q.front();
            res.push_back(f);
            q.pop();
            for (auto& next: adj[f]) {
                indegree[next]--;
                if (indegree[next] == 1) {
                    q.push(next);
                }
            }
        }
       }
       return res;
    }
};
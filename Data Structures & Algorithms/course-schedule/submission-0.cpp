class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& v: prerequisites) {
            in[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        vector<bool> took(numCourses, false);
        int n = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (!in[i]) {
                q.push(i);
                took[i] = true;
                ++n;
            }
        }
        while (q.size() > 0) {
            int c = q.front();
            q.pop();
            for (auto& next: adj[c]) {
                in[next]--;
                if (!in[next] && !took[next]) {
                    q.push(next);
                    took[next] = true;
                    ++n;
                }
            }
        }
        return n == numCourses;
    }
};
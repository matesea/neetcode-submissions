class Solution {
    bool dfs(vector<vector<int>>& rel, vector<vector<int>>& dep, int u, int v) {
        if (dep[u][v] != -1)
            return dep[u][v] == 1;
        for (auto& child: rel[u]) {
            if (dfs(rel, dep, child, v)) {
                dep[u][v] = 1;
                return true;
            }
        }
        dep[u][v] = 0;
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       vector<vector<int>> rel(numCourses, vector<int>());
       vector<vector<int>> dep(numCourses, vector<int>(numCourses, -1));

       for (auto& p: prerequisites) {
        rel[p[0]].push_back(p[1]);
        dep[p[0]][p[1]] = 1;
       }
       vector<bool> res;
       for (auto& q: queries) {
        res.push_back(dfs(rel, dep, q[0], q[1]));
       }
       return res;
    }
};
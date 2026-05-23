class Solution {
    const vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j])
            return dp[i][j];
        int res = 0;
        for (const auto& dir: dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[ni].size())
                continue;
            if (matrix[i][j] >= matrix[ni][nj])
                continue;
            res = max(res, dfs(matrix, ni, nj));
        }
        return dp[i][j] = 1 + res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        dp.resize(m, vector<int>(n, 0));

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }
};

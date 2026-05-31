class Solution {
    vector<vector<int>> dp;
    int dfs(string& w1, string& w2, int i, int j) {
        if (i == w1.size())
            return dp[i][j] = w2.size() - j;
        else if (j == w2.size())
            return dp[i][j] = w1.size() - i;
        else if (dp[i][j] != INT_MAX)
            return dp[i][j];
        int &res = dp[i][j];
        if (w1[i] == w2[j])
            res = min(res, dfs(w1, w2, i + 1, j + 1));
        else {
            res = min(res, dfs(w1, w2, i+1, j) + 1);
            res = min(res, dfs(w1, w2, i, j + 1) + 1);
            res = min(res, dfs(w1, w2, i+1, j+1) + 1);
        }
        return dp[i][j];
    }
public:
    int minDistance(string w1, string w2) {
        int m = w1.size(), n = w2.size();
        dp.resize(m+1, vector<int>(n+1, INT_MAX));
        return dfs(w1, w2, 0, 0);
    }
};

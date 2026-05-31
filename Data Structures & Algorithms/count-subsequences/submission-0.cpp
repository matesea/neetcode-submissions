class Solution {
    vector<vector<int>> dp;
    int dfs(string& s, int i, string& t, int j) {
        if (j >= t.size())
            return 1;
        if (i >= s.size())
            return 0;
        if (dp[i][j] >= 0)
            return dp[i][j];
        int res = 0;
        if (s[i] == t[j])
            res += dfs(s, i+1, t, j+1);
        res += dfs(s, i+1, t, j);
        return dp[i][j] = res;
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (s.size() < t.size())
            return 0;
        dp.resize(m+1, vector<int>(n+1, -1));
        return dfs(s, 0, t, 0);
    }
};

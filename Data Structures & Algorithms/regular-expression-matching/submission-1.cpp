class Solution {
    vector<vector<int>> dp;
    bool dfs(string& s, string& p, int i, int j) {
        if (j == p.size())
            return i == s.size();
        if (dp[i][j] >= 0)
            return dp[i][j] > 0;
        bool match = i < s.size() && (p[j] == s[i] || p[j] == '.');
        if (j + 1 < p.size() && p[j+1] == '*') {
            dp[i][j] = dfs(s, p, i, j + 2) || match && dfs(s, p, i+1, j);
        } else 
            dp[i][j] = match && dfs(s, p, i + 1, j + 1);
        return dp[i][j];
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return dfs(s, p, 0, 0);
    }
};
class Solution {
    vector<vector<int>> dp;
    bool dfs(string& s1, string& s2, int i, int j, string& s3) {
        if (i >= s1.size() && j >= s2.size())
            return true;
        if (dp[i][j] >= 0)
            return dp[i][j] > 0;
        bool res = false;
        if (i < s1.size() && s1[i] == s3[i+j])
            res |= dfs(s1, s2, i+1, j, s3);
        if (!res && j < s2.size() && s2[j] == s3[i+j])
            res |= dfs(s1, s2, i, j+1, s3);
        return dp[i][j] = res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
            return false;
        dp.resize(m+1, vector<int>(n+1, -1));
        return dfs(s1, s2, 0, 0, s3);
    }
};

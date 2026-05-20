class Solution {
    vector<int> dp;
    int dfs(string& s, int i) {
        if (i >= s.size())
            return 1;
        if (dp[i] >= 0)
            return dp[i];
        long long res = 0;
        if (s[i] == '0') return dp[i] = 0;
        if (s[i] == '1' && i+1 < s.size())
            res += dfs(s, i+2);
        if (s[i] == '2' && i+1 < s.size() && '0' <= s[i+1] && s[i+1] <= '6')
            res += dfs(s, i+2);
        res += dfs(s, i + 1);
        return dp[i] = res;
    }
public:
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        dfs(s, 0);
        return dp[0];
    }
};

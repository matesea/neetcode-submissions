class Solution {
    vector<int> dp;
    int dfs(string& s, vector<string>& dictionary, int i) {
        if (i >= s.size())
            return 0;
        if (dp[i] >= 0)
            return dp[i];
        int res = s.size() - i;
        for (auto& w: dictionary) {
            if (w.size() + i > s.size())
                continue;
            int j = 0;
            while (j < w.size() && w[j] == s[i+j]) ++j;
            if (j == w.size()) {
                res = min(res, dfs(s, dictionary, i + w.size()));
            }
        }
        res = min(res, 1 + dfs(s, dictionary, i+1));
        return dp[i] = res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        dp.resize(n, -1);
        return dfs(s, dictionary, 0);
    }
};
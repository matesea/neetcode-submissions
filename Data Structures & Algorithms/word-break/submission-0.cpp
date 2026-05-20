class Solution {
    vector<int> dp;
    bool dfs(string& s, int i, vector<string>& words) {
        if (i >= s.size())
            return true;
        if (dp[i] >= 0)
            return dp[i];
        for (auto& w: words) {
            int j = 0;
            while (j < w.size() && i+j < s.size() && s[i+j] == w[j]) ++j;
            if (j == w.size() && dfs(s, i+j, words))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b) -> bool {
            return a.size() > b.size();
       });
       dp.resize(s.size(), -1);
       return dfs(s, 0, wordDict);
    }
};

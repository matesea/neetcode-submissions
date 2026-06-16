class Solution {
    vector<vector<int>> res;
    void dfs(int n, int i, int k, vector<int>& v) {
        if (v.size() == k) {
            res.push_back(v);
            return;
        } else if (i > n)
            return;
        v.push_back(i);
        dfs(n, i+1, k, v);
        v.pop_back();
        dfs(n, i+1, k, v);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        dfs(n, 1, k, v);
        return res;
    }
};
class Solution {
    int res;
    bool conflict(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first == b.first || a.second == b.second ||
            a.first - a.second == b.first - b.second ||
            a.first + a.second == b.first + b.second;
    }
    void backtrack(vector<pair<int,int>>& v, int n) {
        if (v.size() == n) {
            res++;
            return;
        }
        for (int j = 0; j < n; ++j) {
            pair<int,int> p = {v.size(), j};
            int i;
            for (i = 0; i < v.size(); ++i) {
                if (conflict(v[i], p)) 
                    break;
            }
            if (i == v.size()) {
                v.push_back({v.size(), j});
                backtrack(v, n);
                v.pop_back();
            }
        }
    }
public:
    int totalNQueens(int n) {
        res = 0;
        vector<pair<int,int>> v;
        backtrack(v, n);
        return res;
    }
};
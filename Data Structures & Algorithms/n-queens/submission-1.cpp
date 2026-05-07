class Solution {
    vector<bool> row, col, diag1, diag2;
    vector<vector<string>> res;
    void rec(int n, int i, vector<pair<int,int>>& path) {
        if (i == n) {
            vector<string> s(n, string(n, '.'));
            for (auto& p: path)
                s[p.first][p.second] = 'Q';
            res.push_back(s);
            return; 
        }
        for (int j = 0; j < n; ++j) {
            if (!row[i] && !col[j] && !diag1[i+j] && !diag2[n-1+i-j]) {
                row[i] = col[j] = diag1[i+j] = diag2[n-1+i-j] = true;
                path.push_back({i, j});
                rec(n, i + 1, path);
                row[i] = col[j] = diag1[i+j] = diag2[n-1+i-j] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1)
            return {{"Q"}};
        row.resize(n, false);
        col.resize(n, false);
        diag1.resize(2*n, false);
        diag2.resize(2*n, false);
        vector<pair<int,int>> path;
        rec(n, 0, path);
        return res;
    }
};

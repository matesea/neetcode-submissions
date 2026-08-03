class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       int m = matrix.size(), n = matrix.front().size(); 
       vector<vector<int>> res(n, vector<int>(m, 0));
       for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[j][i] = matrix[i][j];
        }
       }
       return res;
    }
};
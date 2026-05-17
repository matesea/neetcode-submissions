class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        vector<int> row = matrix.front();
        vector<int> col(m);
        for (int i = 0; i < m; ++i)
            col[i] = matrix[i][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (!matrix[i][0]) {
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (!matrix[0][j]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!row[i]) {
                for (int j = 0; j < n; ++j)
                    matrix[0][j] = 0;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (!col[i]) {
                for (int j = 0; j < m; ++j)
                    matrix[j][0] = 0;
                break;
            }
        }
    }
};

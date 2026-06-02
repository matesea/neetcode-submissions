class NumMatrix {
    vector<vector<int>> cop;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        cop = matrix;
        int m = cop.size(), n = cop.front().size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j+1 < n; ++j)
                cop[i][j+1] += cop[i][j];
        for (int i = 0; i+1 < m; ++i)
            for (int j = 0; j < n; ++j)
                cop[i+1][j] += cop[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       row1--, col1--; 
       return cop[row2][col2] - (row1 >= 0 ? cop[row1][col2] : 0)
       - (col1 >=0 ? cop[row2][col1] : 0) + (row1 >=0 && col1 >= 0 ? cop[row1][col1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
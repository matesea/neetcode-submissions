class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        queue<array<int, 3>> q;

        const int dirs[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    q.push({i, j, 0});
            }
        }
        while (q.size() > 0) {
            auto p = q.front();
            q.pop();
            int &i = p[0], &j = p[1], &steps = p[2];
            // cout << "i=" << i << ", j=" << j << ", steps=" << steps << endl;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
                if (grid[ni][nj] < 0)
                    continue;
                if (steps + 1 < grid[ni][nj]) {
                    grid[ni][nj] = steps + 1;
                    q.push({ni, nj, steps + 1});
                }
            }
        }
    }
};

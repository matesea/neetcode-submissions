class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int m = grid.size(), n = grid.front().size(); 
       vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
       queue<pair<int,int>> q;
       const int dirs[][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
       };
       for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2)
                q.push({i, j});
        }
       }
       int steps = 0;
       while (q.size() > 0) {
        int sz = q.size();
        while (sz-- > 0) {
            auto p = q.front();
            q.pop();
            int &x = p.first, &y = p.second;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
       }
       for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 1)
                return -1;
       }
       return steps > 0 ? steps - 1 : 0;
    }
};

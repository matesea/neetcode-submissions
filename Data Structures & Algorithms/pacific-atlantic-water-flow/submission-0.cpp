class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> reachable(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; ++i) {
            reachable[i][0] |= 1;
            reachable[i][n - 1] |= 2;
        }
        for (int i = 0; i < n; ++i) {
            reachable[0][i] |= 1;
            reachable[m - 1][i] |= 2;
        }
        reachable[m-1][0] = reachable[0][n-1] = 3;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachable[i][j] > 0)
                    q.push({i, j});
            }
        }
        char dirs[][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };

        while (q.size() > 0) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && heights[nx][ny] >= heights[x][y] &&
                        reachable[nx][ny] != reachable[x][y])
                {
                    reachable[nx][ny] |= reachable[x][y];
                    q.push({nx, ny});
                }
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachable[i][j] == 3) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
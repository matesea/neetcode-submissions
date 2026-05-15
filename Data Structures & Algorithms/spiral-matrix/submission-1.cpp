class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int,int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
        };
        int dir = 0;
        int m = matrix.size(), n = matrix.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;
        int x = 0, y = 0;
        while (res.size() < m*n) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            int nx, ny;
            nx = x + dirs[dir].first;
            ny = y + dirs[dir].second;
            int i = 0;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny] && i < 3) {
                dir = (dir + 1) % 4;
                nx = x + dirs[dir].first;
                ny = y + dirs[dir].second;
                ++i;
            }
            x = nx, y = ny;
        }
        return res;
    }
};

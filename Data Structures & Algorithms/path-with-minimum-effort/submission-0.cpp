class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights.front().size();
        queue<pair<int,int>> q;
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        efforts[0][0] = 0;
        q.push({0, 0});
        int dirs[][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        while (q.size() > 0) {
            auto p = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = p.first + dirs[k][0];
                int nj = p.second + dirs[k][1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
                int effort = abs(heights[ni][nj] - heights[p.first][p.second]);
                int current = max(effort, efforts[p.first][p.second]);
                if (current < efforts[ni][nj]) {
                    efforts[ni][nj] = current;
                    q.push({ni, nj});
                }
            }
        }
        return efforts[m-1][n-1];
    }
};
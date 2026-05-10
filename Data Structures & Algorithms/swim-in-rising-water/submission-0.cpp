class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int res = grid[0][0]; 
       int m = grid.size(), n = grid.front().size();
       vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
       };

       auto cmp = [&grid](const pair<int,int>& a, const pair<int,int>& b) -> bool {
        return grid[a.first][a.second] > grid[b.first][b.second];
       };
       priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> pq(cmp);
       vector<vector<bool>> inqueue(m, vector<bool>(n, false));
       inqueue[0][0] = true;
       pq.push({0, 0});

       while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        int &x = p.first, &y = p.second;
        res = max(res, grid[x][y]);
        if (x+1 == m && y+1 == n) {
            break;
        }
        for (int k = 0; k < dirs.size(); ++k) {
            int nx = x + dirs[k][0];
            int ny = y + dirs[k][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || inqueue[nx][ny])
                continue;
            inqueue[nx][ny] = true;
            pq.push({nx, ny});
        }
       }
       return res;
    }
};

class Solution {
    vector<int> parent, rank, size;
    int maxArea = 0;
    int root(int x) {
        if (x == parent[x])
            return parent[x];
        return parent[x] = root(parent[x]);
    }
    void join(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y) return;
        if (rank[root_x] > rank[root_y])
            swap(root_x, root_y);
        if (rank[root_x] == rank[root_y])
            rank[root_y]++;
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
        maxArea = max(maxArea, size[root_y]);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        parent.resize(m * n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(m * n, 1);
        size.resize(m * n, 1);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1)
                    continue;
                maxArea = max(maxArea, 1);
                if (i+1 < m && grid[i][j] == grid[i+1][j])
                    join(i*n+j, (i+1)*n+j);
                if (j+1 < n && grid[i][j] == grid[i][j+1])
                    join(i*n+j, i*n+j+1);
            }
        }
        return maxArea;
    }
};

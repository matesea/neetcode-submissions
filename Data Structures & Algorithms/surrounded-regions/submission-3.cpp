class Solution {
    vector<int> parent, rank, size;
    int root(int x) {
        if (x == parent[x])
            return x;
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
        size[root_y] += size[root_x];
        parent[root_x] = root_y;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        parent.resize(m*n+1, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(m*n+1, 1);
        size.resize(m*n+1, 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i+1 < m && board[i][j] == 'O' && board[i+1][j] == 'O')
                    join(i*n+j, (i+1)*n+j);
                if (j+1 < n && board[i][j] == 'O' && board[i][j+1] == 'O')
                    join(i*n+j, i*n+j+1);
                if (i == 0 || i+1 == m || j == 0 || j+1 == n)
                    join(i*n+j, m*n); 
            }
        }
        int border = root(m*n);
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    int r = root(i*n+j);
                    board[i][j] = (r == border ? 'O' : 'X');
                }
            }
        }
    }
};

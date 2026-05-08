class Solution {
    void paint(vector<vector<char>>& board, int i, int j, char color) {
        int m = board.size(), n = board.front().size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != '=')
            return;
        board[i][j] = color;
        paint(board, i + 1, j, color);
        paint(board, i - 1, j, color);
        paint(board, i, j + 1, color);
        paint(board, i, j - 1, color);
    }
    bool dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board.front().size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return false;
        board[i][j] = '=';
        if (i == 0 || j == 0 || i + 1 == m || j + 1 == n) {
            return true;
        }
        if (dfs(board, i + 1, j) || dfs(board, i - 1, j) ||
            dfs(board, i, j + 1) || dfs(board, i, j - 1))
        {
                return true;
        }
        return false;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (dfs(board, i, j))
                        paint(board, i, j, 'O');
                    else
                        paint(board, i, j, 'X');
                }
            }
        }
    }
};

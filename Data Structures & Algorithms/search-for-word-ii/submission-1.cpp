class Solution {
    class trie {
        struct node {
            const vector<int> dr = {1, -1, 0, 0};
            const vector<int> dc = {0, 0, 1, -1};
           vector<node*> children;
            bool end;
            node() {children.resize(26, nullptr); end = false;}
            void find(vector<vector<char>>& board, int x, int y, string& s, unordered_set<string>& res) {
                char c = board[x][y];
                s += c;
                board[x][y] = 0;
                node *p = children[c-'a'];
                if (p->end) res.insert(s);
                for (int k = 0; k < 4; ++k) {
                    int nx = x+dr[k], ny = y+dc[k];
                    if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[nx].size() ||
                        !board[nx][ny] || !p->children[board[nx][ny]-'a']) continue;
                    p->find(board, nx, ny, s, res);
                }
                s.pop_back();
                board[x][y] = c;
            }
        };
        node root;
        public:
        void insert(string& s) {
            node *p = &root;
            for (auto& c: s) {
                if (!p->children[c-'a']) p->children[c-'a'] = new node();
                p = p->children[c-'a'];
            }
            p->end = true;
        }
        void find(vector<vector<char>>& board, int x, int y, unordered_set<string>& res) {
            if (!root.children[board[x][y]-'a']) return;
            string s;
            root.find(board, x, y, s, res);
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie t;
        for (auto& w: words) t.insert(w);
        unordered_set<string> res;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                t.find(board, i, j, res);
        return vector<string>(res.begin(), res.end());
    }
};
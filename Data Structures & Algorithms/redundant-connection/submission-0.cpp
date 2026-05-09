class Solution {
    vector<int> parent, rank;
    int root(int x) {
        if (x == parent[x])
            return parent[x];
        return parent[x] = root(parent[x]);
    }
    bool join(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return true;
        if (rank[x] > rank[y])
            swap(x, y);
        if (rank[x] == rank[y])
            rank[y]++;
        parent[x] = y;
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);

        for (auto& e: edges) {
            if (join(e[0], e[1]))
                return {e[0], e[1]};
        }
        return {};
    }
};

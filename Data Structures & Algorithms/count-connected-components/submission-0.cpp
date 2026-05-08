class Solution {
    vector<int> parent, rank;
    int group;

    int root(int i) {
        return (parent[i] == i) ? i : (parent[i] = root(parent[i]));
    }
    void join(int i, int j) {
        int root_i = root(i);
        int root_j = root(j);
        if (root_i == root_j)
            return;
        if (rank[root_i] > rank[root_j])
            swap(root_i, root_j);
        if (rank[root_i] == rank[root_j])
            rank[root_j]++;
        parent[root_i] = root_j;
        group--;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
        group = n;

        for (auto e: edges)
            join(e[0], e[1]);
        return group;
    }
};

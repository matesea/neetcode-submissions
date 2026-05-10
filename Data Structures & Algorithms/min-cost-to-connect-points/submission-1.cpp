class Solution {
    vector<int> parent, rank;
    int root(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = root(parent[x]);
    }
    void join(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y])
            swap(x, y);
        if (rank[x] == rank[y])
            rank[y]++;
        parent[x] = y;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1)
            return 0;
        auto cmp = [](const array<int,3>& a, const array<int,3>& b) -> bool {
            return a[0] > b[0];
        };
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({dist, i, j});
            }
        }
        parent.resize(points.size(), 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(points.size(), 1);

        int cost = 0, count = 0;
        auto mi = pq.top();
        pq.pop();
        join(mi[1], mi[2]);
        cost += mi[0], count = 2;
        while (count < points.size()) {
            auto mi = pq.top();
            pq.pop();
            if (root(mi[1]) == root(mi[2]))
                continue;
            join(mi[1], mi[2]);
            cost += mi[0]; count++;
        }
        return cost;
    }
};

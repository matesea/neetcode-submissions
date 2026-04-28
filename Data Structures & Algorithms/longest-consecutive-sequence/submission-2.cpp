class Solution {
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    unordered_map<int,int> rank;
    int max_size;
    int root(int x) {
        return parent[x] = (x == parent[x] ? x :  root(parent[x]));
    }
    void join(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y)
            return;
        if (rank[root_x] > rank[root_y])
            swap(root_x, root_y);
        if (rank[root_x] == rank[root_y])
            rank[root_y]++;
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
        max_size = max(max_size, size[root_y]);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        max_size = 0;
        for (auto& c: nums) {
            if (parent.find(c) == parent.end()) {
                parent[c] = c;
                rank[c] = 1;
                size[c] = 1;
                if (parent.find(c - 1) != parent.end())
                    join(c - 1, c);
                if (parent.find(c + 1) != parent.end())
                    join(c, c+1);
                max_size = max(max_size, size[c]);
            }
        }
        return max_size;
    }
};

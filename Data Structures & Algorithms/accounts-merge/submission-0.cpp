class Solution {
    class dsu {
        vector<int> parent, rank;
        public:
        dsu(int n) {
            parent.resize(n, 0);
            rank.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int root(int i) {
            if (parent[i] == i) return i;
            return parent[i] = root(parent[i]);
        }
        void join(int i, int j) {
            int root_i = root(i);
            int root_j = root(j);
            if (root_i == root_j) return;
            if (rank[root_i] > rank[root_j])
                swap(root_i, root_j);
            if (rank[root_i] == rank[root_j])
                rank[root_j]++;
            parent[i] = parent[root_i] = root_j;
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       unordered_map<string,int> email2id; 
       unordered_map<int,string> id2email, id2name;
       int k = 0;
       for (auto& a: accounts) {
        string& name = a[0];
        for (int i = 1; i < a.size(); ++i) {
            string& email = a[i];
            if (email2id.find(email) != email2id.end())
                continue;
            email2id[email] = k;
            id2email[k] = email;
            id2name[k++] = name;
        }
       }
       dsu d(k);
       for (auto& a: accounts) {
        for (int i = 1; i+1 < a.size(); ++i) {
            d.join(email2id[a[i]], email2id[a[i+1]]);
        }
       }
       unordered_set<int> uniq_id;
       for (int i = 0; i < k; ++i) {
        uniq_id.insert(d.root(i));
       }
       vector<vector<string>> res;
       for (auto& id: uniq_id) {
        vector<string> v;
        v.push_back(id2name[id]);
        for (int i = 0; i < k; ++i) {
            if (d.root(i) == id) {
                v.push_back(id2email[i]);
            }
        }
        res.push_back(v);
       }
       return res;
    }
};
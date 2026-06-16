class Solution {
    vector<vector<int>> res;
    void dfs(unordered_map<int,int>& count, int n, vector<int>& v) {
        if (n == v.size()) {
            res.push_back(v);
            return ;
        }
        for (auto& [x, c]: count) {
            if (c > 0) {
                v.push_back(x);
                c--;
                dfs(count, n, v);
                v.pop_back();
                c++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> v;
        for (auto& e: nums) {
            count[e]++;
        }
        dfs(count, nums.size(), v);
        return res;
    }
};
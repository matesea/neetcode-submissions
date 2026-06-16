class Solution {
    set<vector<int>> res;
    void dfs(vector<int>& nums, int mask, vector<int>& v) {
        if (v.size() == nums.size()) {
            res.insert(v);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (mask & (1 << i)) continue;
            v.push_back(nums[i]);
            dfs(nums, mask | (1 << i), v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v;
        dfs(nums, 0, v);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
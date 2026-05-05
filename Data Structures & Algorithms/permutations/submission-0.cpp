class Solution {
    vector<vector<int>> res;
    void dfs(vector<int>& nums, unsigned int mask, vector<int>& v) {
        int sz = nums.size();
        if (nums.size() == v.size()) {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < sz; ++i) {
            if ((1 << i) & mask)
                continue;
            v.push_back(nums[i]);
            dfs(nums, mask | (1 << i), v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        if (nums.size() == 1) {
            res.push_back(nums);
            return res;
        }
        dfs(nums, 0, v);
        return res;
    }
};

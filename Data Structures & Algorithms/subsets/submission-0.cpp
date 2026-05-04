class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& nums, int i, vector<int>& v) {
        if (i == nums.size()) {
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        rec(nums, i + 1, v);
        v.pop_back();
        rec(nums, i + 1, v);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        rec(nums, 0, v);
        return res;
    }
};

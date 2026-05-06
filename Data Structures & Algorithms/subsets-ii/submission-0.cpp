class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& nums, int idx, vector<int>& v) {
        if (idx >= nums.size()) {
            res.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        rec(nums, idx + 1, v);
        v.pop_back();
        int i = idx;
        while (i+1 < nums.size() && nums[i] == nums[i+1]) ++i;
        rec(nums, i+1, v);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
       rec(nums, 0, v);
       return res;
    }
};

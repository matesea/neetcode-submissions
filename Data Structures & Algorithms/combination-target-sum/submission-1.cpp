class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& nums, int i, int target, vector<int>& v) {
        if (!target) {
            res.push_back(v);
            return;
        }
        if (i >= nums.size() || target < 0)
            return;
        if (nums[i] <= target) {
            v.push_back(nums[i]);
            rec(nums, i, target - nums[i], v);
            v.pop_back();
        }
        rec(nums, i + 1, target, v);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
       rec(nums, 0, target, v); 
       return res;
    }
};

class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& nums, int idx, int target, vector<int>& v) {
        if (!target) {
            res.push_back(v);
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (nums[i] > target)
                break;
            v.push_back(nums[i]);
            rec(nums, i, target - nums[i], v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
        sort(nums.begin(), nums.end());
       rec(nums, 0, target, v); 
       return res;
    }
};

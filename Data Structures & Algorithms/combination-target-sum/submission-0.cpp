class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& nums, int i, int sum, int target, vector<int>& v) {
        if (i >= nums.size() || target <= sum) {
            if (target == sum)
                res.push_back(v);
            return;
        }
        rec(nums, i + 1, sum, target, v);
        int k = target / nums[i];
        for (int j = 0; j < k; ++j) {
            v.push_back(nums[i]);
            rec(nums, i + 1, sum + nums[i] * (j + 1), target, v);
        }
        while (k-- > 0)
            v.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
       rec(nums, 0, 0, target, v); 
       return res;
    }
};

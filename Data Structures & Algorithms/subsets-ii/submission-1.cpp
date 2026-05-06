class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& nums, int i, vector<int>& v) {
        res.push_back(v);
        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j-1])
                continue;
            v.push_back(nums[j]);
            rec(nums, j+1, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
       sort(nums.begin(), nums.end()); 
       rec(nums, 0, v);
       return res;
    }
};

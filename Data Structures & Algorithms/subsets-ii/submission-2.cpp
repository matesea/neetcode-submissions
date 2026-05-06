class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> res = {{}}; 
       sort(nums.begin(), nums.end());
       int preIdx = 0, idx = 0;

       for (int i = 0; i < nums.size(); ++i) {
        idx = (i > 0 && nums[i] == nums[i-1] ? preIdx : 0);
        preIdx = res.size();
        for (int j = idx; j < preIdx; ++j) {
            vector<int> tmp = res[j];
            tmp.push_back(nums[i]);
            res.push_back(tmp);
        }
       }
       return res;
    }
};

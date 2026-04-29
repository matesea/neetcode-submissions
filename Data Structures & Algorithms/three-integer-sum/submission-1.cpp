class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
       for (int i = 0; i < n; ++i) {
        int target = -nums[i];
        int j = i+1, k = n-1;
        while (j < k) {
            if (nums[j] + nums[k] == target) {
                res.push_back({nums[i], nums[j], nums[k]});
                while (j+1 < n && nums[j] == nums[j+1]) ++j;
                ++j;
            } else if (nums[j] + nums[k] > target)
                --k;
            else ++j;
        }
        while (i+1 < n && nums[i] == nums[i+1])
            ++i;
       }
       return res;
    }
};

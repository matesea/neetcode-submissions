class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (int j = i + 1; j < n; ++j) {
                if (j > i+1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = n - 1;
                long long reminder = (long long)target - nums[i] - nums[j];
                while (left < right) {
                    if ((long long)nums[left] + nums[right] == reminder) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left-1] == nums[left]) ++left;
                        while (right > left && nums[right] == nums[right+1]) --right;
                    } else if ((long long)nums[left] + nums[right] < reminder)
                        ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};
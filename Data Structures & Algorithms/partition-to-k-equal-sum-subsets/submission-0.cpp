class Solution {
    bool dfs(vector<int>& nums, int mask, int i, int k, int current, int target) {
        if (i == k) return true;
        for (int j = 0; j < nums.size(); ++j) {
            if ((mask & (1 << j)) == 0) {
                if (current + nums[j] < target) {
                    if (dfs(nums, mask | (1 << j), i, k, current + nums[j], target))
                        return true;
                } else if (current + nums[j] == target) {
                    if (dfs(nums, mask | (1 << j), i + 1, k, 0, target))
                        return true;
                }
                
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int target = sum / k;
        if (*max_element(nums.begin(), nums.end()) > target)
            return false;
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, 0, 0, k, 0, target);
    }
};
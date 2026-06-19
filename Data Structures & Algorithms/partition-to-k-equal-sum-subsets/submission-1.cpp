class Solution {
    vector<int> dp;

    int dfs(vector<int>& nums, int mask, int i, int k, int current, int target) {
        if (dp[mask] != -1) return dp[mask];
        if (!k) return dp[mask] = 1;
        if (current == target)
            return dp[mask] = dfs(nums, mask, 0, k - 1, 0, target);
        for (int j = i; j < nums.size(); ++j) {
            if ((mask & (1 << j)) || current + nums[j] > target)
                continue;
            if (dfs(nums, mask | (1 << j), j + 1, k, current + nums[j], target)) {
                return dp[mask] = 1;
            }
            if (!current)
                break;
        }
        return dp[mask] = 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int target = sum / k;
        if (*max_element(nums.begin(), nums.end()) > target)
            return false;
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        dp.resize(1 << n, -1);
        return dfs(nums, 0, 0, k, 0, target);
    }
};
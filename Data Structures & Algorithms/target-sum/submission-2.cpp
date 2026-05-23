class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target < -sum || sum < target)
            return 0;
        vector<int> dp(2*sum + 1, 0);
        dp[sum] = 1;
        for (auto& x: nums) {
            vector<int> next_dp(2*sum + 1, 0);
            for (int i = 0; i <= 2*sum; ++i) {
                if (i-x >= 0) next_dp[i-x] += dp[i];
                if (i+x <= 2*sum) next_dp[i+x] += dp[i];
            }
            dp = next_dp;
        }
        return dp[sum + target];
    }
};

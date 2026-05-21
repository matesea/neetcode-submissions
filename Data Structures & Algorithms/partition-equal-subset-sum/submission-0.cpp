class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        long long target = total >> 1;
        if (total & 1)
            return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (const auto& n: nums) {
            for (int i = target; i >= n; --i)
                dp[i] = (dp[i] | dp[i - n]);
        }
        return dp[target];
    }
};

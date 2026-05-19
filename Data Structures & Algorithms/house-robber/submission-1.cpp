class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n, 0);
       int res = 0;
       for (int i = 0; i < n; ++i) {
        dp[i] = nums[i];
        if (i >= 2) dp[i] = max(dp[i], dp[i-2] + nums[i]);
        if (i >= 3) dp[i] = max(dp[i], dp[i-3] + nums[i]);
        res = max(res, dp[i]);
       }
       return res;
    }
};

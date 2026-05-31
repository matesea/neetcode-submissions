class Solution {
    int rec(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        else if (dp[i][j] > 0)
            return dp[i][j];
        for (int k = i; k <= j; ++k) {
            int gain = nums[i-1] * nums[k] * nums[j+1];
            gain += rec(nums, i, k-1, dp) + rec(nums, k+1, j, dp);
            dp[i][j] = max(dp[i][j], gain);
        }
        return dp[i][j];
    }
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return rec(nums, 1, n-2, dp);
    }
};
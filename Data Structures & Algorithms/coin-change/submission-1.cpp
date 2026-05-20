class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1 + amount, INT_MAX);
        for (int i = 0; i <= amount; ++i) {
            if (i == 0) dp[i] = 0;
            if (dp[i] == INT_MAX) continue;
            for (auto& c: coins) {
                if ((long long)i+c <= amount)
                    dp[i+c] = min(dp[i+c], dp[i]+1);
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};

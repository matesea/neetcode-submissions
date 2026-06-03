class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        dp2[0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp1[i] = max(dp1[i-1], dp2[i-1] + prices[i]);
            dp2[i] = max(dp2[i-1], dp1[i-1] - prices[i]);
        }
        return dp1[n-1];
    }
};
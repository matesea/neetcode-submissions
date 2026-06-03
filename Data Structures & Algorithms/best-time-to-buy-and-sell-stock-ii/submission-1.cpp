class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int reset = 0, held = -prices[0];
        for (int i = 1; i < n; ++i) {
            int old_reset = reset;
            reset = max(reset, held + prices[i]);
            held = max(held, old_reset - prices[i]);
        }
        return reset;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mi = prices[0];
       int profit = 0;
       for (auto& p: prices) {
        mi = min(mi, p);
        profit = max(profit, p - mi);
       }
       return profit;
    }
};

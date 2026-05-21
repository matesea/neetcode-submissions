class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (auto& n: nums) {
            if (!dp.size() || dp.back() < n) {
                dp.push_back(n);
                continue;
            }
            int idx = lower_bound(dp.begin(), dp.end(), n) - dp.begin();
            dp[idx] = n;
        }
        return dp.size();
    }
};

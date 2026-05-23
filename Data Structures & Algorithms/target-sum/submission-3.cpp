class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target < -sum || sum < target)
            return 0;
        unordered_map<int,int> dp;
        dp[0] = 1;
        for (auto& x: nums) {
            unordered_map<int,int> nextdp;
            for (auto [key, value]: dp) {
                nextdp[key-x] += value;
                nextdp[key+x] += value;
            }
            dp = nextdp;
        }
        return dp.find(target) != dp.end() ? dp[target] : 0;
    }
};

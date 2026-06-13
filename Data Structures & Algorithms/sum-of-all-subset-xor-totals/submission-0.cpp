class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int n = nums.size(); 
       int length = (1 << n);
       vector<int> dp(length, 0);
       for (int i = 0; i < length; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) || (i | (1 << j)) >= length)
                continue;
            dp[i | (1 << j)] = dp[i] ^ nums[j];
        }
       }
       return accumulate(dp.begin(), dp.end(), 0);
    }
};
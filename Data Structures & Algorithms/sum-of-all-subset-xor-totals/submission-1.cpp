class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int n = nums.size(); 
       int length = (1 << n);
       vector<int> dp(length, 0);
       for (int i = 0; i < length; ++i) {
        int x = length - 1 - i;
        int j = 0;
        while (x > 0) {
            if (x & 1) {
                dp[i | (1 << j)] = dp[i] ^ nums[j];
            }
            x >>= 1;
            ++j;
        }
       }
       return accumulate(dp.begin(), dp.end(), 0);
    }
};
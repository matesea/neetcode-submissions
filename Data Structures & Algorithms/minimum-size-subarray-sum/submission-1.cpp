class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l = 0, r = 0;
       int current = 0, n = nums.size();
       int res = INT_MAX;
       while (r < n) {
        current += nums[r];
        while (l <= r && current >= target) {
            res = min(res, r - l + 1);
            current -= nums[l++];
        }
        ++r;
       }
       return res == INT_MAX? 0 : res;
    }
};
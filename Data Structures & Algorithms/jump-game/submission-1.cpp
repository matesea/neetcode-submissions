class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farest = 0, i = 0;
        while (i <= farest && i < n) {
            farest = max(farest, i + nums[i]);
            ++i;
        }
        return farest+1 >= n;
    }
};

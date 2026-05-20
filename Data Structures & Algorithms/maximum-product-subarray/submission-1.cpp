class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int mx = nums[0], mi = nums[0]; 
       int res = nums[0];
       for (int i = 1; i < nums.size(); ++i) {
        int new_mx = max(max(nums[i], mx * nums[i]), mi*nums[i]);
        int new_mi = min(min(nums[i], mi * nums[i]), mx*nums[i]);
        mx = new_mx, mi = new_mi;
        res = max(res, max(mx, mi));
       }
       return res;
    }
};

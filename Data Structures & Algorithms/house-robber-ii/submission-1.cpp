class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        int rob3 = 0, rob4 = 0;
        int n = nums.size();
        if (n <= 2)
            return *max_element(nums.begin(), nums.end());
        for (int i = 0; i+1 < n; ++i) {
            int tmp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        for (int i = 1; i < n; ++i) {
            int tmp = max(rob3 + nums[i], rob4);
            rob3 = rob4;
            rob4 = tmp;
        }
        return max(rob2, rob4);
    }
};

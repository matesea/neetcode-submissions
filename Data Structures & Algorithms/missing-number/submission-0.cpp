class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);
        for (auto& x: nums)
            seen[x] = true;
        int i;
        for (i = 0; i <= n; ++i)
            if (!seen[i])
                break;
        return i;
    }
};

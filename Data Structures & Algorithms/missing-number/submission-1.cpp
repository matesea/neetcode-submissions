class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long total = n * (n + 1) / 2;
        for (auto& x: nums)
            total -= x;
        return (int)total;
    }
};

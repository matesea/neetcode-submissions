class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        for (auto& x: nums) {
            total |= x;
        }
        return total << (nums.size() - 1);
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> s(INT_MAX, false);
        for (auto& x: nums) {
            if (x > 0) s[x] = true;
        }
        for (int i = 1; i < INT_MAX; ++i)
            if (!s[i]) return i;
        return -1;
    }
};
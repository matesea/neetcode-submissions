class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mx = max(*max_element(nums.begin(), nums.end()), 1);
        vector<bool> s(mx+1, false);
        for (auto& x: nums) {
            if (x > 0) s[x] = true;
        }
        for (int i = 1; i <= mx; ++i)
            if (!s[i]) return i;
        return mx+1;
    }
};
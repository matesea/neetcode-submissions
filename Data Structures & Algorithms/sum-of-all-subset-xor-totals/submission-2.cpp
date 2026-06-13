class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int n = nums.size(); 
       int length = (1 << n);
       int res = 0;
       for (int i = 0; i < length; ++i) {
        int _xor = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))
                _xor ^= nums[j];
        }
        res += _xor;
       }
       return res;
    }
};
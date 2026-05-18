class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        int res = 0;
        while (n) {
            if (n & 1) {
                res |= (1 << (31 - i));
            }
            n >>= 1;
            ++i;
        }
        return res;
    }
};

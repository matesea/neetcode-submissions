class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        while (n) {
            if (n & 1) x++;
            n >>= 1;
        }
        return x;
    }
};

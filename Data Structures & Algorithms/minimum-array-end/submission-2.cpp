class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        long long k = n - 1;

        for (int i = 0; i < 64 && k > 0; ++i) {
            if (!(((long long)1 << i) & x)) {
                if (k & 1) {
                    res |= (1LL << i);
                }
                k >>= 1;
            }
        }
        return res;
    }
};
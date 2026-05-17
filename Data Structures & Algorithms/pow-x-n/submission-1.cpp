class Solution {
public:
    double myPow(double x, int n) {
        bool reverse = (n < 0);
        n = abs(n);
        if (n == 1) return reverse ? (double)1.0/x : x;
        double res = 1, base = x;
        while (n) {
            if (n & 1) {
                res *= base;
            }
            n >>= 1;
            base *= base;
        }
        return (reverse? ((double)1.0/res) : res);
    }
};

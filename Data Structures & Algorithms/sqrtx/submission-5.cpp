class Solution {
public:
    int mySqrt(int x) {
       if (x < 2) return x;
       int lo = mySqrt(x >> 2) << 1;
       int hi = lo + 1;
       return (long long)hi * hi > x ? lo : hi;
    }
};
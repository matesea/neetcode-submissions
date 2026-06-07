class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while ((long long)r * r > x) {
            r = (r + x / r) >> 1;
        }
        return r;
    }
};
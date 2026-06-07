class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (x / mid == mid)
                return mid;
            if (x / mid < mid)
                hi = mid - 1;
            else lo = mid;
        }
        return lo;
    }
};
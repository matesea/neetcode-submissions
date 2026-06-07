class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = x;
        int res;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if ((long long)mid * mid == x)
                return mid;
            else if ((long long)mid * mid > x)
                hi = mid - 1;
            else {
                res = mid;
                lo = mid + 1;
            }
        }
        return res;
    }
};
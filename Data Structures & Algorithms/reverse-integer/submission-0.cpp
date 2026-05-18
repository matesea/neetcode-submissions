class Solution {
public:
    int reverse(int x) {
        bool _signed = false;
        if (x < 0) {
            _signed = true;
            x = -x;
        }
        int res = 0;;
        while (x) {
            if (res > INT_MAX/10) return 0;
            res = res * 10 + (x % 10);
            x /= 10;
        }
        if (_signed)
            res = -res;
        return res;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        while (a & b) {
            int _carry = (a & b) << 1;
            int _xor = (a ^ b);
            a = _carry;
            b = _xor;
        }
        return a | b;
    }
};
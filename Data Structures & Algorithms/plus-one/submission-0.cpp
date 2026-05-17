class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        vector<int> res;
        for (int i = digits.size() - 1; i >= 0 ; --i) {
            if (i == digits.size() - 1) {
                int digit = (digits[i] + 1) % 10;
                carry = (digits[i] + 1) / 10;
                res.push_back(digit);
            } else {
                int digit = (digits[i] + carry) % 10;
                carry = (digits[i] + carry) / 10;
                res.push_back(digit);
            }
        }
        if (carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.length() < b.length())
            swap(a, b);
        bool carry = false;
        string res;
        for (int i = 0; i < a.size() || carry; ++i) {
            char c = (i < a.size() ? a[i] - '0' : 0);
            c += (i < b.size() ? b[i] - '0' : 0) + carry;
            carry = (c >> 1);
            c &= 1;
            res.push_back('0' + c);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};